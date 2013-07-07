#include "abstract.hpp"

////////////////////////////////////////////////////////////////////

DEFINE_KIND(k_IplImage);
DEFINE_KIND(k_Mat);

////////////////////////////////////////////////////////////////////

void deleteObject(value obj)
{
	delete val_data(obj);
}

/*value iplImageToValue(IplImage *image)
{
	value r = alloc_abstract(k_IplImage, image);
	val_gc(r, neko_cvReleaseImage);
	return r;
}

IplImage *valueToIplImage(value image)
{
	//val_check_kind(image, k_IplImage);
	return (IplImage *)val_data(image);
}*/

value matToValue(Mat mat)
{
	value r = alloc_abstract(k_Mat, new Mat(mat));
	val_gc(r, deleteObject);
	return r;
}

Mat &valueToMat(value mat)
{
	if (!val_is_abstract(mat) || !val_is_kind(mat,k_Mat)) failure("Mat type expected.");
	return *((Mat*)val_data(mat));
}

value pointToValue(Point p)
{
	value r = alloc_object(NULL);
	alloc_field(r, val_id("x"), alloc_int(p.x));
	alloc_field(r, val_id("y"), alloc_int(p.y));
	return r;
}

