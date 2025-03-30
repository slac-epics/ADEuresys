ADEuresys Releases
==================

The latest untagged master branch can be obtained at
https://github.com/areaDetector/ADEuresys.

Tagged source code releases can be obtained at
https://github.com/areaDetector/ADEuresys/tags

The versions of EPICS base, asyn, and other synApps modules used for each release can be obtained from 
the EXAMPLE_RELEASE_PATHS.local, EXAMPLE_RELEASE_LIBS.local, and EXAMPLE_RELEASE_PRODS.local
files respectively, in the configure/ directory of the appropriate release of the 
[top-level areaDetector](https://github.com/areaDetector/areaDetector) repository.


Release Notes
=============

R1-1 (April XXX, 2025)
---------------------
* Added support for features from Transport Layer (TL) modules.
  Previously only camera features (RemoteModule) were supported.
  - Changed EuresysFeature to a template class that uses a module type template parameter.
  - Changed ADEuresys::createFeature to parse the drvInfo prefix of the 
    feature record to determine which module to use.
  - Requires ADGenICam R1-11 which supports prefixes other than GC,
    and contains the Euresys Coaxlink Transport Layer XML, database, and OPI files.

R1-0 (April 10, 2024)
---------------------
* Initial release.
* Tested on Windows 10 and CentOS Stream 9 with 3 cameras:
  * Mikrotron MC2066  CXP-12 X4
  * Adimec Q12-A CXP-6 X4
  * ViewWorks VNP-604MX
