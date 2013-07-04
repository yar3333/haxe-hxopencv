SET SRC_DIR=src
SET OBJ_DIR=obj
SET OUT=..\ndll\Windows\hxOpenCV.ndll

call "c:\Program Files\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
del /Q obj\*.obj > nul

SET INCLUDE_NEKO=d:\MyProg\_tools\motion-twin\neko\include
SET LIBRARY_NEKO=d:\MyProg\_tools\motion-twin\neko

SET INCLUDE_OPENCV=d:\MyProg\_assets\opencv\build\include 
SET LIBRARY_OPENCV=d:\MyProg\_assets\opencv\build\x86\vc10\lib

SET LINKER_OPTIONS=/OUT:%OUT% /NOLOGO /LIBPATH:%LIBRARY_OPENCV% /LIBPATH:%LIBRARY_NEKO% /DLL "opencv_core245d.lib" "opencv_imgproc245d.lib" "opencv_highgui245d.lib" "opencv_ml245d.lib" "opencv_video245d.lib" "opencv_features2d245d.lib" "opencv_calib3d245d.lib" "opencv_objdetect245d.lib" "opencv_contrib245d.lib" "opencv_legacy245d.lib" "opencv_flann245d.lib" "neko.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib"
cl /I%INCLUDE_OPENCV% /I%INCLUDE_NEKO% /nologo /W3 /WX- /Od /Oy- /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_WINDLL" /D "_MBCS" /Gm- /EHsc /RTC1 /MTd /GS /Zc:wchar_t /Zc:forScope /Fo%OBJ_DIR%\ /Gd %SRC_DIR%\*.cpp /link %LINKER_OPTIONS%
