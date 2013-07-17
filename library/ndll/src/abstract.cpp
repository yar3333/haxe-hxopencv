#include "abstract.hpp"

////////////////////////////////////////////////////////////////////

DEFINE_KIND(k_IplImage);
DEFINE_KIND(k_Mat);

////////////////////////////////////////////////////////////////////

void deleteMat(value obj)
{
    delete (Mat *)val_data(obj);
}

void deleteIplImage(value obj)
{
    delete (IplImage *)val_data(obj);
}

value iplImageToValue(IplImage *image)
{
	value r = alloc_abstract(k_IplImage, image);
	val_gc(r, deleteIplImage);
	return r;
}

IplImage *valueToIplImage(value image)
{
	return (IplImage *)val_data(image);
}

value matToValue(Mat mat)
{
	value r = alloc_abstract(k_Mat, new Mat(mat));
	val_gc(r, deleteMat);
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

int *newValueToArrayInt(value arr)
{
	int arrSize = val_array_size(arr);
	value *arrPtr = val_array_ptr(arr);
	int *r = new int[arrSize];
	int *c = r;
	int *endC = c + arrSize;
	while (c < endC)
	{
		value v = *arrPtr;
		val_check_type_or_fail(v, int);
		*c = val_int(v);
		c++;
		arrPtr++;
	}
	return r;
}

Scalar valueToScalar(value arr)
{
	int arrSize = val_array_size(arr);
	value *arrPtr = val_array_ptr(arr);
	switch (arrSize)
	{
		case 1: return Scalar(val_number(arrPtr[0]));
		case 2: return Scalar(val_number(arrPtr[0]), val_number(arrPtr[1]));
		case 3: return Scalar(val_number(arrPtr[0]), val_number(arrPtr[1]), val_number(arrPtr[2]));
		case 4: return Scalar(val_number(arrPtr[0]), val_number(arrPtr[1]), val_number(arrPtr[2]), val_number(arrPtr[3]));
	}
	failure("Array for scalar must contain from 1 to 4 items.");
    return Scalar();
}
