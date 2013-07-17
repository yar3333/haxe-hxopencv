#include "abstract.hpp"

////////////////////////////////////////////////////////////////////

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
			r = matToValue(Mat(val_array_size(dimensions), newDimensions, itemType, valueToScalar(itemInitValue)));
		}
		else
		{
			r = matToValue(Mat(val_array_size(dimensions), newDimensions, itemType));
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

//---------------------------------------------------

value neko_Mat_initByArray(value mat, value arr)
{
	val_check_kind_or_fail(mat, k_Mat);
	
	Mat &img = valueToMat(mat);
    int channels = img.channels();
    int elemSize1 = img.elemSize1();
    
    value *arrPtr = val_array_ptr(arr);
    
	for(int row = 0; row < img.rows && row < val_array_size(arr); row++, arrPtr++)
	{
		uchar *p = img.ptr(row);
        value arrRow = *arrPtr;
        val_check_type_or_fail(arrRow, array);
        value *arrRowPtr = val_array_ptr(arrRow);
        for(int col = 0; col < img.cols && col < val_array_size(arrRow); col++, arrRowPtr++)
		{
            if (elemSize1 == 1)
            {
                switch (channels)
                {
                    case 1:
                        val_check_type_or_fail(*arrRowPtr, int);
                        *p = val_int(*arrRowPtr);
                        p += elemSize1;
                        break;
                }
            }
            else
            if (elemSize1 == 4)
            {
                switch (channels)
                {
                    case 1:
                        val_check_type_or_fail(*arrRowPtr, number);
                        *((float *)p) = (float)val_number(*arrRowPtr);
                        p += elemSize1;
                        break;
                }
            }
		}
    }
    
    return val_null;
}
DEFINE_PRIM(neko_Mat_initByArray, 2);
