#include "abstract.hpp"

////////////////////////////////////////////////////////////////////

value neko_imread(value fileName, value loadImageColor)
{
	val_check(fileName, string);
	val_check(loadImageColor, int);
	return matToValue(imread(val_string(fileName), val_int(loadImageColor)));
}
DEFINE_PRIM(neko_imread, 2);

//---------------------------------------------------

