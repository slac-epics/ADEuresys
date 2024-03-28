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

R1-0 (April XXX, 2024)
-------------------
* Initial release.
  The following things need to be fixed before the first release:
  - Build trigger cable, test trigger modes
  - Ask Euresy
    - Why can't EGrabber Studio display the ViewWorks camera?
      - They have asked for trace output.
    - When using Single or Multiple mode is there a way to know when acquisition is complete? 
      - They answered this, need to implement.
    - Why can't it reach the maximum frame rate of 1798 frames/s on Mikrotron in Mono10 mode?
      On Linux it does 1668 and on Windows 1703.
