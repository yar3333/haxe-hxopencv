SRC_DIR = src
OBJ_DIR = obj
OBJS=$(OBJ_DIR)/abstract.o $(OBJ_DIR)/mat.o $(OBJ_DIR)/core.o $(OBJ_DIR)/imgproc.o $(OBJ_DIR)/highgui.o $(OBJ_DIR)/test.o

ifdef WINDOWS

	INCLUDE_NEKO=d:/MyProg/_tools/motion-twin/neko/include
	LIBRARY_NEKO=d:/MyProg/_tools/motion-twin/neko
	INCLUDE_OPENCV=d:/MyProg/_assets/opencv/build/include 
	LIBRARY_OPENCV=d:/MyProg/_assets/opencv/build/x86/vc10/lib
	
	OUT=../ndll/Windows/hxOpenCV.ndll
	
	CCFLAGS=-I$(INCLUDE_OPENCV) -I$(INCLUDE_NEKO) -nologo -W3 -WX- -Od -Oy- -D "WIN32" -D "_WINDOWS" -D "_USRDLL" -D "_WINDLL" -D "_MBCS" -Gm- -EHsc -RTC1 -GS -Zc:wchar_t -Zc:forScope -Gd -MTd
	
	LDFLAGS=-NOLOGO -LIBPATH:$(LIBRARY_OPENCV) -LIBPATH:$(LIBRARY_NEKO) -DLL
	LDFLAGS+=neko.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib
	LDFLAGS+=opencv_core245d.lib opencv_imgproc245d.lib opencv_highgui245d.lib opencv_ml245d.lib opencv_video245d.lib opencv_features2d245d.lib opencv_calib3d245d.lib opencv_objdetect245d.lib opencv_contrib245d.lib opencv_legacy245d.lib opencv_flann245d.lib neko.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib

build: $(OBJS)
	link $(LDFLAGS) -OUT:$(OUT) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	cl $(CCFLAGS) -c -Fo$@ $<

else

	INCLUDE_NEKO=
	LIBRARY_NEKO=
	INCLUDE_OPENCV=
	LIBRARY_OPENCV=
	
	OUT=../ndll/Linux/hxOpenCV.ndll
	
	CCFLAGS=-shared -O2 -s -Wall -I$(INCLUDE_NEKO) -I$(INCLUDE_OPENCV)
	
	LDFLAGS=-shared -L$(LIBRARY_NEKO) -L$(LIBRARY_OPENCV) $(LIBRARY_NEKO)\neko.dll -lopencv_core245 -lopencv_imgproc245 -lopencv_highgui245 -lopencv_ml245 -lopencv_video245 -lopencv_features2d245 -lopencv_calib3d245 -lopencv_objdetect245 -lopencv_contrib245 -lopencv_legacy245 -lopencv_flann245
	LDFLAGS+=-lneko
	LDFLAGS+=-lopencv_core245 -lopencv_imgproc245 -lopencv_highgui245 -lopencv_ml245 -lopencv_video245 -lopencv_features2d245 -lopencv_calib3d245 -lopencv_objdetect245 -lopencv_contrib245 -lopencv_legacy245 -lopencv_flann245

build: $(OBJS)
	g++ $(OBJS) -o $(OUT) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CCFLAGS) -c -o $@ $<

endif

clean:
	rm -f $(OUT)
	rm -f $(OBJS)

all: clean build
