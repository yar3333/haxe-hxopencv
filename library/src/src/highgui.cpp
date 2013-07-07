#include "abstract.hpp"

#include <stdio.h>

////////////////////////////////////////////////////////////////////

value neko_imread(value fileName, value loadImageColor)
{
	val_check(fileName,string);
	val_check(loadImageColor,int);
	Mat mat = imread(val_string(fileName), val_int(loadImageColor));
	return matToValue(mat);
}
DEFINE_PRIM(neko_imread, 2);

//---------------------------------------------------

