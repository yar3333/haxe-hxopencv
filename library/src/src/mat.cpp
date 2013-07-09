#include "abstract.hpp"

////////////////////////////////////////////////////////////////////

value neko_Mat_create()
{
	return matToValue(*(new Mat()));
}
DEFINE_PRIM(neko_Mat_create, 0);

value neko_Mat_clone(value mat)
{
	val_check_kind_or_fail(mat, k_Mat);
	
	return matToValue(valueToMat(mat).clone());
}
DEFINE_PRIM(neko_Mat_clone, 1);

//---------------------------------------------------
