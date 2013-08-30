#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>
#include <neko.h>

////////////////////////////////////////////////////////////////////

#define STRINGIFY(x) #x
#define val_check_type_or_fail(v, t) if (!val_is_##t(v)) { failure("Excepted "#t" in `"__FILE__"' at line "STRINGIFY(__LINE__)"."); }
#define val_check_kind_or_fail(v, t) if (!val_is_abstract(v) || !val_is_kind(v, t)) { failure("Excepted "#t" in `"__FILE__"' at line "STRINGIFY(__LINE__)"."); }

////////////////////////////////////////////////////////////////////

DECLARE_KIND(k_IplImage);
DECLARE_KIND(k_Mat);
DECLARE_KIND(k_AnnMlp);

////////////////////////////////////////////////////////////////////

using namespace cv;

////////////////////////////////////////////////////////////////////

void deleteMat(value obj);
void deleteIplImage(value obj);
void deleteAnnMlp(value obj);

////////////////////////////////////////////////////////////////////

value iplImageToValue(IplImage *image);
IplImage *valueToIplImage(value image);

value matToValue(const Mat &mat);
Mat &valueToMat(value mat);

value pointToValue(Point p);
Point valueToPoint(value p);

int *newValueToArrayInt(value arr);

Scalar valueToScalar(value arr);

value annMlpToValue(CvANN_MLP *annMlp);
CvANN_MLP *valueToAnnMlp(value annMlp);

CvANN_MLP_TrainParams valueToAnnMlpTrainParams(value params);
