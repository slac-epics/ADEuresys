#ifndef ADEURESYS_H
#define ADEURESYS_H

#include <epicsEvent.h>

#include <ADGenICam.h>
#include <EGrabber.h>

using namespace Euresys;

typedef EGrabber<CallbackSingleThread> EGRABBER_CALLBACK;

#define ESTimeStampModeString               "ES_TIME_STAMP_MODE"                // asynParamInt32, R/O
#define ESUniqueIdModeString                "ES_UNIQUE_ID_MODE"                 // asynParamInt32, R/O
#define ESBufferSizeString                  "ES_BUFFER_SIZE"                    // asynParamInt32, R/O
#define ESBufferQueueSizeString             "ES_BUFFER_QUEUE_SIZE"              // asynParamInt32, R/O
#define ESMessageQueueSizeString            "ES_MESSAGE_QUEUE_SIZE"             // asynParamInt32, R/O
#define ESMessageQueueFreeString            "ES_MESSAGE_QUEUE_FREE"             // asynParamInt32, R/O
#define ESProcessTotalTimeString            "ES_PROCESS_TOTAL_TIME"             // asynParamFloat64, R/O
#define ESProcessCopyTimeString             "ES_PROCESS_COPY_TIME"              // asynParamFloat64, R/O


/** Main driver class inherited from areaDetectors ADDriver class.
 * One instance of this class will control one camera.
 */
class ADEuresys : public ADGenICam
{
public:
    ADEuresys(const char *portName, int cameraId, int numSPBuffers,
              size_t maxMemory, int priority, int stackSize);

    // virtual methods to override from ADGenICam
    virtual asynStatus writeInt32( asynUser *pasynUser, epicsInt32 value);
    //virtual asynStatus writeFloat64( asynUser *pasynUser, epicsFloat64 value);
    void report(FILE *fp, int details);
    virtual GenICamFeature *createFeature(GenICamFeatureSet *set, 
                                          std::string const & asynName, asynParamType asynType, int asynIndex,
                                          std::string const & featureName, GCFeatureType_t featureType);
    
    void processFrame(ScopedBuffer &buf);
    EGRABBER_CALLBACK *getGrabber();
    void shutdown();

private:
    int ESTimeStampMode;
#define FIRST_ES_PARAM ESTimeStampMode
    int ESUniqueIdMode;
    int ESBufferSize;
    int ESBufferQueueSize;
    int ESMessageQueueSize;
    int ESMessageQueueFree;
    int ESProcessTotalTime;
    int ESProcessCopyTime;

    /* Local methods to this class */
    asynStatus startCapture();
    asynStatus stopCapture();
    asynStatus connectCamera();
    asynStatus disconnectCamera();
    asynStatus setROI();
    void reportNode(FILE *fp, const char *nodeName, int level);

    /* Data */
    EGRABBER_CALLBACK *mGrabber_;
    int boardNum_;
    int numEGBuffers_;
    int bitsPerPixel_;
    int exiting_;
    int uniqueId_;
};

#endif

