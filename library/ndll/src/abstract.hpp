#include <stdlib.h>
#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <neko.h>

////////////////////////////////////////////////////////////////////

#define STRINGIFY(x) #x
#define val_check_type_or_fail(v, t) if (!val_is_##t(v)) { failure("Excepted "#t" in `"__FILE__"' at line "STRINGIFY(__LINE__)"."); }
#define val_check_kind_or_fail(v, t) if (!val_is_abstract(v) || !val_is_kind(v, t)) { failure("Excepted "#t" in `"__FILE__"' at line "STRINGIFY(__LINE__)"."); }

////////////////////////////////////////////////////////////////////

DECLARE_KIND(k_IplImage);
DECLARE_KIND(k_Mat);

////////////////////////////////////////////////////////////////////

using namespace cv;

////////////////////////////////////////////////////////////////////

void deleteMat(value obj);
void deleteIplImage(value obj);

////////////////////////////////////////////////////////////////////

value iplImageToValue(IplImage *image);
IplImage *valueToIplImage(value image);
value matToValue(Mat mat);
Mat &valueToMat(value mat);
value pointToValue(Point p);
int *newValueToArrayInt(value arr);
Scalar valueToScalar(value arr);
