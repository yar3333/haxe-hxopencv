#include "abstract.hpp"

////////////////////////////////////////////////////////////////////

value neko_minMaxLoc(value src, value mask)
{
	val_check_kind_or_fail(src, k_Mat);
	if (!val_is_null(mask))
	{
		val_check_kind_or_fail(mask, k_Mat);
	}
	
	double minVal, maxVal;
	Point minLoc, maxLoc;
	
	minMaxLoc(valueToMat(src), &minVal, &maxVal, &minLoc, &maxLoc, !val_is_null(mask) ? valueToMat(mask) : noArray());

	value r = alloc_object(NULL);
	alloc_field(r, val_id("minVal"), alloc_float(minVal));
	alloc_field(r, val_id("maxVal"), alloc_float(maxVal));
	alloc_field(r, val_id("minLoc"), pointToValue(minLoc));
	alloc_field(r, val_id("maxLoc"), pointToValue(maxLoc));
	return r;

}
DEFINE_PRIM(neko_minMaxLoc, 2);

//---------------------------------------------------

