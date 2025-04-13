#!/bin/bash

# Note, this needs a recent version of Python to handle UTF-8 characters in the XML file.
# On RHEL7 I use "conda activate base" to get a working version.

# Use this line for int64out and int64in records.  Requires EPICS base 3.16.1 or later, or EPICS 7.
#python scripts/makeDb.py xml/$1.xml --devInt64 GenICamApp/Db/$1.template $2 $3

# Use this line for ao and ai records on older versions of EPICS base. 
# Limits GenICam Integer features to 52 bits because ao and ai records with 64-bit floats are used.
python3 scripts/makeDb.py xml/Euresys_Coaxlink_TLDataStream_25_02_0.xml EuresysApp/Db/Euresys_Coaxlink_TLDataStream_25_02_0.template --prefix DS
python3 scripts/makeAdl.py xml/Euresys_Coaxlink_TLDataStream_25_02_0.xml EuresysApp/op/adl/Euresys_Coaxlink_TLDataStream_25_02_0 --prefix DS

python3 scripts/makeDb.py xml/Euresys_Coaxlink_TLDevice_25_02_0.xml EuresysApp/Db/Euresys_Coaxlink_TLDevice_25_02_0.template --prefix DV
python3 scripts/makeAdl.py xml/Euresys_Coaxlink_TLDevice_25_02_0.xml EuresysApp/op/adl/Euresys_Coaxlink_TLDevice_25_02_0 --prefix DV

python3 scripts/makeDb.py xml/Euresys_Coaxlink_TLInterface_25_02_0.xml EuresysApp/Db/Euresys_Coaxlink_TLInterface_25_02_0.template --prefix IF
python3 scripts/makeAdl.py xml/Euresys_Coaxlink_TLInterface_25_02_0.xml EuresysApp/op/adl/Euresys_Coaxlink_TLInterface_25_02_0 --prefix IF

python3 scripts/makeDb.py xml/Euresys_Coaxlink_TLSystem_25_02_0.xml EuresysApp/Db/Euresys_Coaxlink_TLSystem_25_02_0.template --prefix SY
python3 scripts/makeAdl.py xml/Euresys_Coaxlink_TLSystem_25_02_0.xml EuresysApp/op/adl/Euresys_Coaxlink_TLSystem_25_02_0 --prefix SY

#python3 scripts/makeDb.py xml/$1.xml EuresysApp/Db/$1.template $2 $3
#python3 scripts/makeAdl.py xml/$1.xml EuresysApp/op/adl/$1 $2 $3
