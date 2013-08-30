package opencv2;

import neko.Lib;

class HighGui
{
	public static inline var CV_LOAD_IMAGE_UNCHANGED 	= -1;
	public static inline var CV_LOAD_IMAGE_GRAYSCALE 	= 0;
	public static inline var CV_LOAD_IMAGE_COLOR 		= 1;
	public static inline var CV_LOAD_IMAGE_ANYDEPTH 	= 2;
	public static inline var CV_LOAD_IMAGE_ANYCOLOR 	= 4;
	
    public static inline var CV_IMWRITE_JPEG_QUALITY 				= 1;
    public static inline var CV_IMWRITE_PNG_COMPRESSION 			= 16;
    public static inline var CV_IMWRITE_PNG_STRATEGY 				= 17;
    public static inline var CV_IMWRITE_PNG_BILEVEL 				= 18;
    public static inline var CV_IMWRITE_PNG_STRATEGY_DEFAULT 		= 0;
    public static inline var CV_IMWRITE_PNG_STRATEGY_FILTERED 		= 1;
    public static inline var CV_IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY 	= 2;
    public static inline var CV_IMWRITE_PNG_STRATEGY_RLE 			= 3;
    public static inline var CV_IMWRITE_PNG_STRATEGY_FIXED 			= 4;
    public static inline var CV_IMWRITE_PXM_BINARY 					= 32;
	
	public static function imread(fileName:String, loadImageColor=1) : Mat
	{
		return new Mat(neko_imread(Lib.haxeToNeko(fileName), loadImageColor));
	}
	private static var neko_imread = Lib.load("opencv", "neko_imread", 2);
	
	public static function imwrite(fileName:String, img:Mat, params:Array<Int>) : Bool
	{
		return neko_imwrite(Lib.haxeToNeko(fileName), img.h, Lib.haxeToNeko(params));
	}
	private static var neko_imwrite = Lib.load("opencv", "neko_imwrite", 3);
}
