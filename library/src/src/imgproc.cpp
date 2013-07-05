#include "abstract.hpp"

////////////////////////////////////////////////////////////////////

void neko_matchTemplate(value image, value templ, value result, value method)
{
	matchTemplate(valueToMat(image), valueToMat(templ), valueToMat(result), val_int(method));
}
DEFINE_PRIM(neko_matchTemplate, 4);

//---------------------------------------------------
