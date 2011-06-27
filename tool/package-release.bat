@rem Note: (1) Set VER to release version. (2) Install ActivePerl.

setlocal
set VER=0.0
set TARGET=release\kinect-mssdk-openni-bridge-%VER%
rmdir /s /q %TARGET%
mkdir %TARGET%
xcopy ..\bin %TARGET%\bin\ /e
copy ..\LICENSE.TXT %TARGET%
copy ..\README_*.TXT %TARGET%
copy ..\HISTORY_*.TXT %TARGET%
perl zip.pl %TARGET%
copy %TARGET%.zip ..\release