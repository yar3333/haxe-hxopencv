package;

import opencv.OpenCV;

class TestsA extends haxe.unit.TestCase
{
    public function testBasic()
    {
		OpenCV.init();
		this.assertTrue(true);
    }
}
