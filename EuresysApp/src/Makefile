TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#=============================

DBD += ADEuresysSupport.dbd

USR_INCLUDES += -I$(EURESYS_EGRABBER_INCLUDE)
#USR_INCLUDES_Linux += -I$(BITFLOW_UTILS_INCLUDE)/BFGTLUtil
#USR_LDFLAGS_WIN32 += /LIBPATH:$(BITFLOW_SDK_LIB)

LIBRARY_IOC_Linux += ADEuresys
LIBRARY_IOC_WIN32 += ADEuresys
ADEuresys_SRCS += EuresysFeature.cpp
ADEuresys_SRCS += ADEuresys.cpp

LIB_LIBS += ADGenICam

include $(ADCORE)/ADApp/commonLibraryMakefile

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

