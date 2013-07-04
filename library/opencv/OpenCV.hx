package opencv;

import neko.Lib;

class OpenCV
{
	public static function cvTest() : Void
	{
		neko_cvTest();
	}
	
	private static var neko_cvTest = Lib.load("hxOpenCV","neko_cvTest", 0);
}
