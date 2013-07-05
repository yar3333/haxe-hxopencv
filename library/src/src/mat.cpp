#include "abstract.hpp"

////////////////////////////////////////////////////////////////////

value neko_Mat_clone(value mat)
{
	return matToValue(valueToMat(mat).clone());
}
DEFINE_PRIM(neko_Mat_clone, 1);

//---------------------------------------------------
