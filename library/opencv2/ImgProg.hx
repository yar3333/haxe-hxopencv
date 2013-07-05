package opencv2;

import neko.Lib;

class ImgProg
{
	public static function matchTemplate(image:Mat, templ:Mat, result:Mat, method:Int) : Void
	{
		neko_matchTemplate(image.h, templ.h, result.h, method);
	}
	private static var neko_matchTemplate = Lib.loadLazy("hxOpenCV", "neko_matchTemplate", 4);
}

