package opencv2;

import neko.Lib;

class ImgProc
{
    public static inline var TM_SQDIFF        	= 0;
    public static inline var TM_SQDIFF_NORMED 	= 1;
    public static inline var TM_CCORR         	= 2;
    public static inline var TM_CCORR_NORMED  	= 3;
    public static inline var TM_CCOEFF        	= 4;
    public static inline var TM_CCOEFF_NORMED 	= 5;
	
	public static inline var THRESH_BINARY      	= 0;  /* value = value > threshold ? max_value : 0       */
    public static inline var THRESH_BINARY_INV		= 1;  /* value = value > threshold ? 0 : max_value       */
    public static inline var THRESH_TRUNC       	= 2;  /* value = value > threshold ? threshold : value   */
    public static inline var THRESH_TOZERO      	= 3;  /* value = value > threshold ? value : 0           */
    public static inline var THRESH_TOZERO_INV  	= 4;  /* value = value > threshold ? 0 : value           */
    public static inline var THRESH_MASK        	= 7;
    public static inline var THRESH_OTSU        	= 8;
	
	public static inline var ADAPTIVE_THRESH_MEAN_C		= 0;
	public static inline var ADAPTIVE_THRESH_GAUSSIAN_C	= 1;
	
	private static inline var IPL_BORDER_CONSTANT		= 0;
	private static inline var IPL_BORDER_REPLICATE		= 1;
	private static inline var IPL_BORDER_REFLECT		= 2;
	private static inline var IPL_BORDER_WRAP			= 3;
	private static inline var IPL_BORDER_REFLECT_101 	= 4;
	private static inline var IPL_BORDER_TRANSPARENT 	= 5;
	
	public static inline var BORDER_REPLICATE 	= IPL_BORDER_REPLICATE;
	public static inline var BORDER_CONSTANT 	= IPL_BORDER_CONSTANT;
	public static inline var BORDER_REFLECT 	= IPL_BORDER_REFLECT;
	public static inline var BORDER_WRAP 		= IPL_BORDER_WRAP;
	public static inline var BORDER_REFLECT_101 = IPL_BORDER_REFLECT_101;
	public static inline var BORDER_REFLECT101 	= BORDER_REFLECT_101;
	public static inline var BORDER_TRANSPARENT = IPL_BORDER_TRANSPARENT;
	public static inline var BORDER_DEFAULT 	= BORDER_REFLECT_101;
	public static inline var BORDER_ISOLATED 	= 16;
	
	public static function matchTemplate(image:Mat, templ:Mat, result:Mat, method:Int) : Void
	{
		neko_matchTemplate(image.h, templ.h, result.h, method);
	}
	private static var neko_matchTemplate = Lib.loadLazy("opencv", "neko_matchTemplate", 4);
	
	public static function threshold(src:Mat, dst:Mat, thresh:Float, maxval:Float, type:Int) : Void
	{
		neko_threshold(src.h, dst.h, thresh, maxval, type);
	}
	private static var neko_threshold = Lib.loadLazy("opencv", "neko_threshold", 5);
	
	public static function adaptiveThreshold(src:Mat, dst:Mat, maxValue:Float, adaptiveMethod:Int, thresholdType:Int, blockSize:Int, C:Float) : Void
	{
		neko_adaptiveThreshold(src.h, dst.h, maxValue, adaptiveMethod, thresholdType, blockSize, C);
	}
	private static var neko_adaptiveThreshold = Lib.loadLazy("opencv", "neko_adaptiveThreshold", -1);
	
	public static function invert(src:Mat, dst:Mat) : Void
	{
		neko_invert(src.h, dst.h);
	}
	private static var neko_invert = Lib.loadLazy("opencv", "neko_invert", 2);
	
	public static function filter2D(src:Mat, dst:Mat, ddepth=-1, kernel:Mat, anchorX=-1, anchorY=-1, delta=0.0, borderType=BORDER_DEFAULT) : Void
	{
		neko_filter2D(src.h, dst.h, ddepth, kernel.h, anchorX, anchorY, delta, borderType);
	}
	private static var neko_filter2D = Lib.loadLazy("opencv", "neko_filter2D", -1);
	
	public static function erode(src:Mat, dst:Mat, kernel:Mat, anchorX=-1, anchorY=-1, iterations=1, borderType=BORDER_CONSTANT, ?borderType:Array<Float>) : Void
	{
		neko_erode(src.h, dst.h, kernel.h, anchorX, anchorY, iterations, borderType, Lib.haxeToNeko(borderType));
	}
	private static var neko_erode = Lib.loadLazy("opencv", "neko_erode", -1);
	
	public static function dilate(src:Mat, dst:Mat, kernel:Mat, anchorX=-1, anchorY=-1, iterations=1, borderType=BORDER_CONSTANT, ?borderType:Array<Float>) : Void
	{
		neko_dilate(src.h, dst.h, kernel.h, anchorX, anchorY, iterations, borderType, Lib.haxeToNeko(borderType));
	}
	private static var neko_dilate = Lib.loadLazy("opencv", "neko_dilate", -1);
}

