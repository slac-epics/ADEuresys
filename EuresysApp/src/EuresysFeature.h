#ifndef EURESYS_FEATURE_H
#define EURESYS_FEATURE_H

#include <GenICamFeature.h>

#include <ADEuresys.h>

#include "EGrabber.h"
using namespace Euresys;

static const char *className = "EuresysFeature";

template <typename ModuleType> class EuresysFeature : public GenICamFeature
{
public:

    EuresysFeature(GenICamFeatureSet *set, 
                         std::string const & asynName, asynParamType asynType, int asynIndex,
                         std::string const & featureName, GCFeatureType_t featureType)
                         
             : GenICamFeature(set, asynName, asynType, asynIndex, featureName, featureType),
             mAsynUser(set->getUser()),
             mFeatureName(featureName)
    {
        static const char *functionName = "EuresysFeature";
    
        ADEuresys *pDrv = (ADEuresys *) mSet->getPortDriver();
        mGrabber = pDrv->getGrabber();
        try {
            mIsImplemented = mGrabber->getInteger<ModuleType>(query::implemented(mFeatureName)) ? true : false;
        }
        catch (std::exception &e) {
            asynPrint(mAsynUser, ASYN_TRACE_ERROR, "%s::%s query error for implemented=%s\n", 
                      className, functionName, e.what());
        }
    }
    
    
    bool isImplemented() { 
        return mIsImplemented; 
    }
    
    bool isAvailable() {
        static const char *functionName = "isAvailable";
        bool value = false;
        if (!mIsImplemented) return value;
        try {
            value = mGrabber->getInteger<ModuleType>(query::available(mFeatureName)) ? true : false;
        }
        catch (std::exception &e) {
            reportError(functionName, "query error for available", e.what());
        }
        return value;
     }
    
    bool isReadable() {
        static const char *functionName = "isReadable";
        bool value = false; 
        if (!mIsImplemented) return value;
        try {
            value = mGrabber->getInteger<ModuleType>(query::readable(mFeatureName)) ? true : false;
        }
        catch (std::exception &e) {
            reportError(functionName, "query error for readable", e.what());
        }
        return value;
    }
    
    bool isWritable() {
        static const char *functionName = "isWritable";
        bool value = false; 
        if (!mIsImplemented) return value;
        try {
            value = mGrabber->getInteger<ModuleType>(query::writeable(mFeatureName)) ? true : false;
        }
        catch (std::exception &e) {
            reportError(functionName, "query error for writeable", e.what());
        }
        return value;
    }
    
    epicsInt64 readInteger() {
        static const char *functionName = "readInteger";
        epicsInt64 value = 0;
        try {
            value = mGrabber->getInteger<ModuleType>(mFeatureName);
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling getInteger", e.what());
        }
        return value;
    }
    
    epicsInt64 readIntegerMin() {
        static const char *functionName = "readIntegerMin";
        epicsInt64 value = 0;
        try {
            value = mGrabber->getInteger<ModuleType>(mFeatureName+".Min");
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling getInteger", e.what());
        }
        return value;
    }
    
    epicsInt64 readIntegerMax() {
        static const char *functionName = "readIntegerMax";
        epicsInt64 value = 0;
        try {
            value = mGrabber->getInteger<ModuleType>(mFeatureName+".Max");
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling getInteger", e.what());
        }
        return value;
    }
    
    epicsInt64 readIncrement() { 
        static const char *functionName = "readIncrement";
        epicsInt64 value = 0;
        try {
            value = mGrabber->getInteger<ModuleType>(mFeatureName+".Inc");
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling getInteger", e.what());
        }
        return value;
    }
    
    void writeInteger(epicsInt64 value) { 
        static const char *functionName = "writeInteger";
        try {
            mGrabber->setInteger<ModuleType>(mFeatureName, value);
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling setInteger", e.what());
        }
    }
    
    bool readBoolean() { 
        static const char *functionName = "readBoolean";
        epicsInt64 value = 0;
        try {
            value = mGrabber->getInteger<ModuleType>(mFeatureName);
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling getInteger", e.what());
        }
        return value ? true : false;
    }
    
    void writeBoolean(bool bval) {
        static const char *functionName = "writeBoolean";
        epicsInt64 value = bval ? 1 : 0;
        try {
            mGrabber->setInteger<ModuleType>(mFeatureName, value);
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling setInteger", e.what());
        }
    }
    
    // The Mikrotron cameras use integer node types for ExposureTime and AcquisitionFrameRate but ADGenICam expects these to be float nodes.
    // These double methods need to handle integers
    double readDouble() {
        static const char *functionName = "readDouble";
        epicsFloat64 value = 0;
        try {
            value = mGrabber->getFloat<ModuleType>(mFeatureName);
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling getFloat", e.what());
        }
        return value;
    }
    
    void writeDouble(double value) { 
        static const char *functionName = "writeDouble";
        try {
            mGrabber->setFloat<ModuleType>(mFeatureName, value);
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling setFloat", e.what());
        }
    }
    
    double readDoubleMin() {
        static const char *functionName = "readDoubleMin";
        epicsFloat64 value = 0;
        try {
            value = mGrabber->getFloat<ModuleType>(mFeatureName+".Min");
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling getFloat", e.what());
        }
        return value;
    }
    
    double readDoubleMax() {
        static const char *functionName = "readDoubleMax";
        epicsFloat64 value = 0;
        try {
            value = mGrabber->getFloat<ModuleType>(mFeatureName+".Max");
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling getFloat", e.what());
        }
        return value;
    }
    
    int readEnumIndex() { 
        static const char *functionName = "readEnumIndex";
        epicsInt64 value=0;
        try {
            value = mGrabber->getInteger<ModuleType>(mFeatureName);
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling getInteger", e.what());
        }
        return (int) value;
    }
    
    void writeEnumIndex(int value) {
        static const char *functionName = "writeEnumIndex";
        try {
            mGrabber->setInteger<ModuleType>(mFeatureName, (epicsInt64)value);
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling setInteger", e.what());
        }
    }
    
    std::string readEnumString() { 
        static const char *functionName = "readEnumString";
        std::string value;
        try {
            value = mGrabber->getString<ModuleType>(mFeatureName);
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling getString", e.what());
        }
        return value;
    }
    
    void writeEnumString(std::string const &value) { 
    }
    
    std::string readString() { 
        static const char *functionName = "readString";
        std::string value;
        try {
            value = mGrabber->getString<ModuleType>(mFeatureName);
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling getString", e.what());
        }
        return value;
    }
    
    void writeString(std::string const & value) { 
        static const char *functionName = "writeString";
        try {
            mGrabber->setString<ModuleType>(mFeatureName, value);
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling setString", e.what());
        }
    }
    
    void writeCommand() {
        static const char *functionName = "writeCommand";
        try {
            mGrabber->execute<ModuleType>(mFeatureName);
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling execute", e.what());
        }
    }
    
    void readEnumChoices(std::vector<std::string>& enumStrings, std::vector<int>& enumValues) {
        static const char *functionName = "readEnumChoices";
        std::vector<std::string> strs;
        try {
            strs = mGrabber->getStringList<ModuleType>(query::enumEntries(mFeatureName));
        }
        catch (std::exception &e) {
            reportError(functionName, "error calling getStrings", e.what());
        }
        enumStrings = strs;
        epicsInt64 ival=0;
        for (size_t i=0; i<strs.size(); i++) {
            try {
                ival = mGrabber->getInteger<ModuleType>(mFeatureName+".Entry."+enumStrings[i]);
            }
            catch (std::exception &e) {
                reportError(functionName, "error calling getInteger", e.what());
            }
            enumValues.push_back((int)ival);
        }
    }

private:
    void reportError(const char *functionName, const char *errorSource, const char *errorWhat) {
        asynPrint(mAsynUser, ASYN_TRACE_ERROR, "%s::%s feature=%s %s=%s\n",
                  className, functionName, mFeatureName.c_str(), errorSource, errorWhat);
    }
    asynUser *mAsynUser;
    EGRABBER_CALLBACK *mGrabber;
    std::string mFeatureName;
    bool mIsImplemented;

};

#endif
