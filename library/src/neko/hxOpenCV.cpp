#include <stdlib.h>
#include <string.h>
#include <neko.h>

#include "OpenCvWrapper.h"

#define STRINGIFY(x) #x
#define val_match_or_fail(v, t) if(!val_is_##t(v)) { failure("Excepted "#t" in `"__FILE__"' at line "STRINGIFY(__LINE__)"."); }

value hxcurl_init()
{
	help();
	return val_true;
}
DEFINE_PRIM(hxcurl_init,0);
