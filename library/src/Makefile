SRC_DIR = src
OBJ_DIR = obj

INCLUDE_NEKO = d:/MyProg/_tools/motion-twin/neko/include
LIBRARY_NEKO = d:/MyProg/_tools/motion-twin/neko

INCLUDE_OPENCV = d:/MyProg/_assets/opencv/build/include 
LIBRARY_OPENCV = d:/MyProg/_assets/opencv/build/x86/mingw/lib

CC = g++

CFLAGS = -O2 -s -Wall -I$(INCLUDE_NEKO) -I$(INCLUDE_OPENCV)
#LDFLAGS = -L$(LIBRARY_NEKO) -L$(LIBRARY_OPENCV) -lneko -lopencv_core245 -lopencv_imgproc245 -lopencv_highgui245 -lopencv_ml245 -lopencv_video245 -lopencv_features2d245 -lopencv_calib3d245 -lopencv_objdetect245 -lopencv_contrib245 -lopencv_legacy245 -lopencv_flann245
LDFLAGS = -L$(LIBRARY_NEKO) -L$(LIBRARY_OPENCV) d:\MyProg\_tools\motion-twin\neko\neko.dll -lopencv_core245 -lopencv_imgproc245 -lopencv_highgui245 -lopencv_ml245 -lopencv_video245 -lopencv_features2d245 -lopencv_calib3d245 -lopencv_objdetect245 -lopencv_contrib245 -lopencv_legacy245 -lopencv_flann245
 

OUT = ../ndll/Windows/hxOpenCV.ndll

OBJ = $(OBJ_DIR)/abstract.o $(OBJ_DIR)/mat.o $(OBJ_DIR)/core.o $(OBJ_DIR)/imgproc.o $(OBJ_DIR)/highgui.o $(OBJ_DIR)/test.o

hxOpenCV: $(OBJ)
	$(CC) -shared $(OBJ) -o $(OUT) $(LDFLAGS)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean:
	rm -f $(OUT)
	rm -f $(OBJ)

all: clean hxOpenCV
