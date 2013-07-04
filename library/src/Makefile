SRC_DIR = src
OBJ_DIR = obj

INCLUDE_NEKO = d:/MyProg/_tools/motion-twin/neko/include
LIBRARY_NEKO = d:/MyProg/_tools/motion-twin/neko

INCLUDE_OPENCV = d:/MyProg/_assets/opencv/build/include 
LIBRARY_OPENCV = d:/MyProg/_assets/opencv/build/x86/mingw/lib

CC = vcc

CFLAGS = -O2 -s -Wall -shared -I$(INCLUDE_NEKO) -I$(INCLUDE_OPENCV)
LDFLAGS = -L$(LIBRARY_NEKO) -L$(LIBRARY_OPENCV) -lneko -lopencv_core245 -lopencv_imgproc245 -lopencv_highgui245 -lopencv_ml245 -lopencv_video245 -lopencv_features2d245 -lopencv_calib3d245 -lopencv_objdetect245 -lopencv_contrib245 -lopencv_legacy245 -lopencv_flann245
#LDFLAGS = -L$(LIBRARY_NEKO) -L$(LIBRARY_OPENCV) -lneko -static -lopencv_core245.dll -lopencv_imgproc245.dll -lopencv_highgui245.dll -lopencv_ml245.dll -lopencv_video245.dll -lopencv_features2d245.dll -lopencv_calib3d245.dll -lopencv_objdetect245.dll -lopencv_contrib245.dll -lopencv_legacy245.dll -lopencv_flann245.dll

OUT = ../../ndll/Windows/hxOpenCV.ndll

OBJ = $(OBJ_DIR)/hxOpenCV.o

hxOpenCV: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OUT) $(LDFLAGS)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean:
	rm -f $(OUT)
	rm -f $(OBJ)

all: clean hxOpenCV
