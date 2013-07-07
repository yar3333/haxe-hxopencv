#include "abstract.hpp"

////////////////////////////////////////////////////////////////////

value neko_Mat_create()
{
	return matToValue(*(new Mat()));
}
DEFINE_PRIM(neko_Mat_create, 0);

value neko_Mat_clone(value mat)
{
	return matToValue(valueToMat(mat).clone());
}
DEFINE_PRIM(neko_Mat_clone, 1);

//---------------------------------------------------
