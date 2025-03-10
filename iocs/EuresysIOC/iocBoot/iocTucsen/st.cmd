< envPaths
errlogInit(20000)

dbLoadDatabase("$(TOP)/dbd/EuresysApp.dbd")
EuresysApp_registerRecordDeviceDriver(pdbbase) 

# Use this line for a specific board
epicsEnvSet("BOARD_ID", "0")

# The maximim image width; used for row profiles in the NDPluginStats plugin
epicsEnvSet("XSIZE",  "6144")
# The maximim image height; used for column profiles in the NDPluginStats plugin
epicsEnvSet("YSIZE",  "6144")

# Need to create Tucsen_CXP_Dhyana6060BSI.template at ADGenICam EPICS driver
epicsEnvSet("GENICAM_DB_FILE", "$(ADGENICAM)/db/Tucsen_CXP_Dhyana6060BSI.template")

< ../st_base.cmd
