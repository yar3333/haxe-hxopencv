#include "abstract.hpp"

////////////////////////////////////////////////////////////////////

value neko_Mat_create(value width, value height)
{
	return matToValue(*(new Mat()));
}
DEFINE_PRIM(neko_Mat_create, 0);

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
