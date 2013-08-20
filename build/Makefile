ifeq ($(shell getconf LONG_BIT),64)
	X64=1
endif

SRC_DIR = src
OBJ_DIR = obj

INCLUDE_NEKO=
LIBRARY_NEKO=
INCLUDE_OPENCV=
LIBRARY_OPENCV=

OUT=../library/ndll/Linux/hxOpenCV.ndll

CCFLAGS=-shared -O2 -s -Wall -I$(INCLUDE_NEKO) -I$(INCLUDE_OPENCV)

LDFLAGS=-shared -L$(LIBRARY_NEKO) -L$(LIBRARY_OPENCV) $(LIBRARY_NEKO)\neko.dll -lopencv_core245 -lopencv_imgproc245 -lopencv_highgui245 -lopencv_ml245 -lopencv_video245 -lopencv_features2d245 -lopencv_calib3d245 -lopencv_objdetect245 -lopencv_contrib245 -lopencv_legacy245 -lopencv_flann245
LDFLAGS+=-lneko
LDFLAGS+=-lopencv_core245 -lopencv_imgproc245 -lopencv_highgui245 -lopencv_ml245 -lopencv_video245 -lopencv_features2d245 -lopencv_calib3d245 -lopencv_objdetect245 -lopencv_contrib245 -lopencv_legacy245 -lopencv_flann245

OBJS=$(OBJ_DIR)/abstract.o $(OBJ_DIR)/mat.o $(OBJ_DIR)/core.o $(OBJ_DIR)/imgproc.o $(OBJ_DIR)/highgui.o $(OBJ_DIR)/ann_mlp.o $(OBJ_DIR)/test.o

build: $(OBJS)
	g++ $(OBJS) -o $(OUT) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CCFLAGS) -c -o $@ $<

clean:
	rm -f $(OUT)
	rm -f $(OBJS)

all: clean build
