package opencv2;

import neko.Lib;

private typedef _Mat = { __Mat:Dynamic };

class Mat
{
	public var h(default, null) : _Mat;

	public function new(h:_Mat)
	{
		this.h = h;
	}
	
	public static function create() : Mat
	{
		return new Mat(neko_Mat_create());
	}
	
	public function clone() : Mat
	{
		return new Mat(neko_Mat_clone(h));
	}
	
	private static var neko_Mat_create = Lib.loadLazy("hxOpenCV", "neko_Mat_create", 0);
	private static var neko_Mat_clone = Lib.loadLazy("hxOpenCV", "neko_Mat_clone", 1);
}
