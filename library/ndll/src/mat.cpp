#include "abstract.hpp"

////////////////////////////////////////////////////////////////////

// template<typename _Tp> class Scalar_ : public Vec<_Tp, 4> { ... };
// typedef Scalar_<double> Scalar;


// CV_[The number of bits per item][Signed or Unsigned][Type Prefix]C[The channel number]
// Mat L(3,sz, CV_8UC(1), Scalar::all(0));
// Mat M(2,2, CV_8UC3, Scalar(0,0,255));	
value neko_Mat_create(value dimensions, value bitsPerItem, value itemTypePrefix, value channelNumber, value itemInitValue)
{
	if (!val_is_null(dimensions))
	{
		val_check_type_or_fail(dimensions, array);
		val_check_type_or_fail(bitsPerItem, int);
		val_check_type_or_fail(itemTypePrefix, string);
		val_check_type_or_fail(channelNumber, int);
			
        int itemType;
		int channelNumberInt = val_int(channelNumber);
		switch (val_int(bitsPerItem))
		{
			case 8:
				itemType = strcmp(val_string(itemTypePrefix), "S")==0 ? CV_8SC(channelNumberInt) : CV_8UC(channelNumberInt);
				break;
			case 16:
				itemType = strcmp(val_string(itemTypePrefix), "S")==0 ? CV_16SC(channelNumberInt) : CV_16UC(channelNumberInt);
				break;
			case 32:
				itemType = strcmp(val_string(itemTypePrefix), "S")==0 ? CV_32SC(channelNumberInt) : CV_32FC(channelNumberInt);
				break;
			case 64:
				itemType = CV_64FC(channelNumberInt);
				break;
			default:
				failure("Excepted channelNumber in '"__FILE__"' at line "STRINGIFY(__LINE__)".");
		}
		
		int *newDimensions = newValueToArrayInt(dimensions);
		value r;
		if (!val_is_null(itemInitValue))
		{
			val_check_type_or_fail(itemInitValue, array);
			r = matToValue(*(new Mat(val_array_size(dimensions), newDimensions, itemType, valueToScalar(itemInitValue))));
		}
		else
		{
			r = matToValue(*(new Mat(val_array_size(dimensions), newDimensions, itemType)));
		}
		delete [] newDimensions;
		return r;
	}
	else
	{
		return matToValue(*(new Mat()));		
	}
}
DEFINE_PRIM(neko_Mat_create, 5);

//---------------------------------------------------

value neko_Mat_clone(value mat)
{
	val_check_kind_or_fail(mat, k_Mat);
	
	return matToValue(valueToMat(mat).clone());
}
DEFINE_PRIM(neko_Mat_clone, 1);

//---------------------------------------------------

value neko_Mat_extractRect(value mat, value x0, value y0, value width, value height)
{
	val_check_kind_or_fail(mat, k_Mat);
	val_check_type_or_fail(x0, int);
	val_check_type_or_fail(y0, int);
	val_check_type_or_fail(width, int);
	val_check_type_or_fail(height, int);
	
	return matToValue(*(new Mat(valueToMat(mat)(Rect(val_int(x0), val_int(y0), val_int(width), val_int(height))))));
}
DEFINE_PRIM(neko_Mat_extractRect, 5);

//---------------------------------------------------

value neko_Mat_rows(value mat)
{
	val_check_kind_or_fail(mat, k_Mat);
	return alloc_int(valueToMat(mat).rows);
}
DEFINE_PRIM(neko_Mat_rows, 1);

//---------------------------------------------------

value neko_Mat_cols(value mat)
{
	val_check_kind_or_fail(mat, k_Mat);
	return alloc_int(valueToMat(mat).cols);
}
DEFINE_PRIM(neko_Mat_cols, 1);
