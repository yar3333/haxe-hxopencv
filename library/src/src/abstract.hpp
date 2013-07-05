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

inline value iplImageToValue(IplImage *image)
{
	value r = alloc_abstract(k_IplImage, image);
	//val_gc(r, neko_cvReleaseImage);
	return r;
}

inline IplImage *valueToIplImage(value image)
{
	//val_check_kind(image, k_IplImage);
	return (IplImage *)val_data(image);
}

inline value matToValue(Mat image)
{
	value r = alloc_abstract(k_Mat, new Mat(image));
	//val_gc(r, neko_cvReleaseImage);
	return r;
}

inline Mat &valueToMat(value image)
{
	//val_check_kind(image, k_Mat);
	return *((Mat*)val_data(image));
}
