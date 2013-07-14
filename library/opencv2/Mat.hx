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
	
	/**
	 * @param	dimensions		Array of dimensions.
	 * @param	bitsPerItem		Bits per channel (8, 16, 32 or 64).
	 * @param	itemTypePrefix	"S", "U" of "F".
	 * @param	channelNumber	Count of the channels (1-4).
	 * @param	itemInitValue	Value to init. Ommit if initialization don't needed.
	 * @return
	 */
	public static function create(?dimensions:Array<Int>, ?bitsPerItem:Int, ?itemTypePrefix:String, ?channelNumber:Int, ?itemInitValue:Array<Float>) : Mat
	{
		return new Mat(neko_Mat_create(Lib.haxeToNeko(dimensions), bitsPerItem, Lib.haxeToNeko(itemTypePrefix), channelNumber, Lib.haxeToNeko(itemInitValue)));
	}
	private static var neko_Mat_create = Lib.loadLazy("hxOpenCV", "neko_Mat_create", 5);
	
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
