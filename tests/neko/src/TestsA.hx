package;

import opencv.OpenCV;

class TestsA extends haxe.unit.TestCase
{
    public function testBasic()
    {
		OpenCV.cvTest();
		this.assertTrue(true);
    }
}
