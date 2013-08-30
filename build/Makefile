include Makefile.platform
include Makefile.ndll

PROJECT=opencv

ifeq ($(PLATFORM),Windows)
	CCFLAGS+= -Id:/MyProg/_assets/opencv/build/include
	LDFLAGS+= -Ld:/MyProg/_assets/opencv/build/x86/mingw/bin
	LDFLAGS+= -l opencv_core245 -l opencv_imgproc245 -l opencv_highgui245 -l opencv_ml245 -l opencv_video245 -l opencv_features2d245 
	LDFLAGS+= -l opencv_calib3d245 -l opencv_objdetect245 -l opencv_contrib245 -l opencv_legacy245 -l opencv_flann245
endif
