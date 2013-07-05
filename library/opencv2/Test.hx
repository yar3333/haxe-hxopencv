package opencv2;

import neko.Lib;

class Test
{
	public static function test() 
	{
		neko_test();
	}
	
	private static var neko_test = Lib.loadLazy("hxOpenCV","neko_test", 0);
}