package opencv2;

import neko.Lib;

class HighGui
{
	public static inline var CV_LOAD_IMAGE_UNCHANGED = -1;
	public static inline var CV_LOAD_IMAGE_GRAYSCALE = 0;
	public static inline var CV_LOAD_IMAGE_COLOR = 1;
	public static inline var CV_LOAD_IMAGE_ANYDEPTH = 2;
	public static inline var CV_LOAD_IMAGE_ANYCOLOR = 4;
	
	public static function imread(fileName:String, loadImageColor=1) : Mat
	{
		return new Mat(neko_imread(fileName, loadImageColor));
	}
	
	private static var neko_imread = Lib.loadLazy("hxOpenCV", "neko_imread", 2);
}
