ADEuresys Releases
==================

The latest untagged master branch can be obtained at
https://github.com/areaDetector/ADEuresys.

Tagged source code releases can be obtained at
https://github.com/areaDetector/ADBitFlow/tags

The versions of EPICS base, asyn, and other synApps modules used for each release can be obtained from 
the EXAMPLE_RELEASE_PATHS.local, EXAMPLE_RELEASE_LIBS.local, and EXAMPLE_RELEASE_PRODS.local
files respectively, in the configure/ directory of the appropriate release of the 
[top-level areaDetector](https://github.com/areaDetector/areaDetector) repository.


Release Notes
=============

R1-0 (March XXX, 2024)
-------------------
* Initial release.
  The following things need to be fixed before the first release:
  - Change Integer features to obey Increment.  This is in ADGenICam
  - Get Mono10 and Mono12 working
  - Build trigger cable, test trigger modes
  - Get Linux build working
  - Ask Euresy
    - What statistics are available (frame loss, etc.)
    - How to read integer Value of each Enum feature entry
    - How to determine the type of each Feature (integer, float, enum, command, etc.)
    - Is unique frame number available?
