package opencv;

import neko.Lib;

class OpenCV
{
	public static function init() : Void
	{
		hxcurl_init();
	}
	
	private static var hxcurl_init = Lib.load("hxOpenCV","hxcurl_init", 0);
}
