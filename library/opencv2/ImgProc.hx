package opencv2;

import neko.Lib;

class ImgProc
{
    public static inline var CV_TM_SQDIFF        = 0;
    public static inline var CV_TM_SQDIFF_NORMED = 1;
    public static inline var CV_TM_CCORR         = 2;
    public static inline var CV_TM_CCORR_NORMED  = 3;
    public static inline var CV_TM_CCOEFF        = 4;
    public static inline var CV_TM_CCOEFF_NORMED = 5;
	
	public static function matchTemplate(image:Mat, templ:Mat, result:Mat, method:Int) : Void
	{
		neko_matchTemplate(image.h, templ.h, result.h, method);
	}
	private static var neko_matchTemplate = Lib.loadLazy("hxOpenCV", "neko_matchTemplate", 4);
}

