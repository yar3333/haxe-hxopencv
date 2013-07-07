#include <stdlib.h>
#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <neko.h>

////////////////////////////////////////////////////////////////////

#define STRINGIFY(x) #x
#define val_match_or_fail(v, t) if(!val_is_##t(v)) { failure("Excepted "#t" in `"__FILE__"' at line "STRINGIFY(__LINE__)"."); }

////////////////////////////////////////////////////////////////////

DECLARE_KIND(k_IplImage);
DECLARE_KIND(k_Mat);

////////////////////////////////////////////////////////////////////

using namespace cv;

////////////////////////////////////////////////////////////////////

extern void deleteObject(value obj);

////////////////////////////////////////////////////////////////////

extern value iplImageToValue(IplImage *image);
extern IplImage *valueToIplImage(value image);
extern value matToValue(Mat mat);
extern Mat &valueToMat(value mat);
extern value pointToValue(Point p);
