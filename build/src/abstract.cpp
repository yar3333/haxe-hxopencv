#include "abstract.hpp"

////////////////////////////////////////////////////////////////////

DEFINE_KIND(k_IplImage);
DEFINE_KIND(k_Mat);
DEFINE_KIND(k_AnnMlp);

////////////////////////////////////////////////////////////////////

void deleteMat(value obj)
{
    delete (Mat *)val_data(obj);
}

void deleteIplImage(value obj)
{
    delete (IplImage *)val_data(obj);
}

void deleteAnnMlp(value obj)
{
    delete (CvANN_MLP *)val_data(obj);
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

value matToValue(const Mat &mat)
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

Point valueToPoint(value p)
{
	if (!val_is_object(p)) failure("Point type expected.");
	return Point(val_int(val_field(p, val_id("x"))), val_int(val_field(p, val_id("y"))));
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

value annMlpToValue(CvANN_MLP *annMlp)
{
	value r = alloc_abstract(k_Mat, annMlp);
	val_gc(r, deleteAnnMlp);
	return r;
}

CvANN_MLP *valueToAnnMlp(value annMlp)
{
	if (!val_is_abstract(annMlp) || !val_is_kind(annMlp, k_AnnMlp)) failure("CvANN_MLP type expected.");
	return (CvANN_MLP*)val_data(annMlp);
}

CvANN_MLP_TrainParams valueToAnnMlpTrainParams(value params)
{
	if (!val_is_object(params)) failure("CvANN_MLP_TrainParams type expected.");

	value term_crit_value = val_field(params, val_id("term_crit")); // CvTermCriteria
	CvTermCriteria term_crit;
	term_crit.type = val_int(val_field(term_crit_value, val_id("type")));
	term_crit.max_iter = val_int(val_field(term_crit_value, val_id("max_iter")));
	term_crit.epsilon = val_number(val_field(term_crit_value, val_id("epsilon")));

	int train_method = val_int(val_field(params, val_id("train_method")));
	double param1 = val_number(val_field(params, val_id("param1")));
	double param2 = val_number(val_field(params, val_id("param2")));

	return CvANN_MLP_TrainParams(term_crit, train_method, param1, param2);
}