package opencv2;

import neko.Lib;

private typedef _Mat = { __Mat:Dynamic };

class Mat
{
	public var h(default, null) : _Mat;
	
	public var rows(get_rows, null) : Int;
	public var cols(get_cols, null) : Int;

	public function new(h:_Mat)
	{
		this.h = h;
	}
	
	public static function create() : Mat
	{
		return new Mat(neko_Mat_create());
	}
	private static var neko_Mat_create = Lib.loadLazy("hxOpenCV", "neko_Mat_create", 0);
	
	public function clone() : Mat
	{
		return new Mat(neko_Mat_clone(h));
	}
	private static var neko_Mat_clone = Lib.loadLazy("hxOpenCV", "neko_Mat_clone", 1);
	
	public function extractRect(x0:Int, y0:Int, width:Int, height:Int) : Mat
	{
		return new Mat(neko_Mat_extractRect(h, x0, y0, width, height));
	}
	private static var neko_Mat_extractRect = Lib.loadLazy("hxOpenCV", "neko_Mat_extractRect", 5);
	
	private function get_rows()
	{
		return neko_Mat_rows(h);
	}
	private static var neko_Mat_rows = Lib.loadLazy("hxOpenCV", "neko_Mat_rows", 1);
	
	private function get_cols()
	{
		return neko_Mat_cols(h);
	}
	private static var neko_Mat_cols = Lib.loadLazy("hxOpenCV", "neko_Mat_cols", 1);
}
