#include "abstract.hpp"

////////////////////////////////////////////////////////////////////

value neko_matchTemplate(value image, value templ, value result, value method)
{
	val_check_kind_or_fail(image, k_Mat);
	val_check_kind_or_fail(templ, k_Mat);
	val_check_kind_or_fail(result, k_Mat);
	val_check_type_or_fail(method, int);
	
	matchTemplate(valueToMat(image), valueToMat(templ), valueToMat(result), val_int(method));
	
	return val_null;
}
DEFINE_PRIM(neko_matchTemplate, 4);

//---------------------------------------------------

value neko_threshold(value src, value dst, value thresh, value maxval, value type)
{
	val_check_kind_or_fail(src, k_Mat);
	val_check_kind_or_fail(dst, k_Mat);
	val_check_type_or_fail(thresh, number);
	val_check_type_or_fail(maxval, number);
	val_check_type_or_fail(type, int);
	
	double r = threshold(valueToMat(src), valueToMat(dst), val_number(thresh), val_number(maxval), val_int(type));
	
	return alloc_float(r);
}
DEFINE_PRIM(neko_threshold, 5);

//---------------------------------------------------

value neko_adaptiveThreshold(value args[], int argc)
{
	if (argc != 7) failure("adaptiveThreshold: expected 7 arguments.");
	
	value src = args[0];
	value dst = args[1];
	value maxValue = args[2];
	value adaptiveMethod = args[3];
	value thresholdType = args[4];
	value blockSize = args[5];
	value C = args[6];
	
	val_check_kind_or_fail(src, k_Mat);
	val_check_kind_or_fail(dst, k_Mat);
	val_check_type_or_fail(maxValue, number);
	val_check_type_or_fail(adaptiveMethod, int);
	val_check_type_or_fail(thresholdType, int);
	val_check_type_or_fail(blockSize, int);
	val_check_type_or_fail(C, number);
	
	adaptiveThreshold(valueToMat(src), valueToMat(dst), val_number(maxValue), val_int(adaptiveMethod), val_int(thresholdType), val_int(blockSize), val_number(C));
	
	return val_null;
}
DEFINE_PRIM_MULT(neko_adaptiveThreshold);
