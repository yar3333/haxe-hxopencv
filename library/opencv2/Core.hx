package opencv2;

import neko.Lib;

class Core
{
	public static function minMaxLoc(mat:Mat, ?mask:Mat) : { minVal:Float, maxVal:Float, minLoc:{x:Int, y:Int}, maxLoc:{x:Int, y:Int} }
	{
		return neko_minMaxLoc(mat.h, mask != null ? mask.h : null);
	}
	private static var neko_minMaxLoc = Lib.loadLazy("opencv", "neko_minMaxLoc", 2);
}
