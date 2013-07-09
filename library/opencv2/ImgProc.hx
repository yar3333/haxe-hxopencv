package opencv2;

import neko.Lib;

class ImgProc
{
    public static inline var CV_TM_SQDIFF        	= 0;
    public static inline var CV_TM_SQDIFF_NORMED 	= 1;
    public static inline var CV_TM_CCORR         	= 2;
    public static inline var CV_TM_CCORR_NORMED  	= 3;
    public static inline var CV_TM_CCOEFF        	= 4;
    public static inline var CV_TM_CCOEFF_NORMED 	= 5;
	
	public static inline var CV_THRESH_BINARY      	= 0;  /* value = value > threshold ? max_value : 0       */
    public static inline var CV_THRESH_BINARY_INV	= 1;  /* value = value > threshold ? 0 : max_value       */
    public static inline var CV_THRESH_TRUNC       	= 2;  /* value = value > threshold ? threshold : value   */
    public static inline var CV_THRESH_TOZERO      	= 3;  /* value = value > threshold ? value : 0           */
    public static inline var CV_THRESH_TOZERO_INV  	= 4;  /* value = value > threshold ? 0 : value           */
    public static inline var CV_THRESH_MASK        	= 7;
    public static inline var CV_THRESH_OTSU        	= 8;
	
	public static function matchTemplate(image:Mat, templ:Mat, result:Mat, method:Int) : Void
	{
		neko_matchTemplate(image.h, templ.h, result.h, method);
	}
	private static var neko_matchTemplate = Lib.loadLazy("hxOpenCV", "neko_matchTemplate", 4);
	
	public static function threshold(src:Mat, dst:Mat, thresh:Float, maxval:Float, type:Int) : Void
	{
		neko_threshold(src.h, dst.h, thresh, maxval, type);
	}
	private static var neko_threshold = Lib.loadLazy("hxOpenCV", "neko_threshold", 5);
	
	public static function adaptiveThreshold(src:Mat, dst:Mat, maxValue:Float, adaptiveMethod:Int, thresholdType:Int, blockSize:Int, C:Float) : Void
	{
		neko_adaptiveThreshold(src.h, dst.h, maxValue, adaptiveMethod, thresholdType, blockSize, C);
	}
	private static var neko_adaptiveThreshold = Lib.loadLazy("hxOpenCV", "neko_adaptiveThreshold", -1);
}

