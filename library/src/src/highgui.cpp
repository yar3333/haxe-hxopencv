#include "abstract.hpp"

////////////////////////////////////////////////////////////////////

value neko_imread(value fileName, value loadImageColor)
{
	val_check_type_or_fail(fileName, string);
	val_check_type_or_fail(loadImageColor, int);
	
	Mat mat = imread(val_string(fileName), val_int(loadImageColor));
	
	return matToValue(mat);
}
DEFINE_PRIM(neko_imread, 2);

//---------------------------------------------------

value neko_imwrite(value fileName, value img, value params)
{
	val_check_type_or_fail(fileName, string);
	val_check_kind_or_fail(img, k_Mat);
	val_check_type_or_fail(params, array);
	
	value *paramValues = val_array_ptr(params);
	vector<int> paramInts;
	for (int i=0; i<val_array_size(params); i++)
	{
		value v = paramValues[i];
		val_check_type_or_fail(v, int);
		paramInts.push_back(val_int(v));
	}
	int r = imwrite(val_string(fileName), valueToMat(img), paramInts);
	
	return alloc_bool(r);
}
DEFINE_PRIM(neko_imwrite, 3);
 
//---------------------------------------------------
