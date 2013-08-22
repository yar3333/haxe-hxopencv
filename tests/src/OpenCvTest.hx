package;

import opencv2.Test;
import opencv2.Core;
import opencv2.HighGui;
import opencv2.ImgProc;
import opencv2.Mat;
import opencv2.AnnMlp;

class OpenCvTest extends haxe.unit.TestCase
{
    public function testBasic()
    {
		Test.test();
		this.assertTrue(true);
    }
    
	public function testMatchTemplate()
    {
		var captcha = HighGui.imread("captcha.jpg", HighGui.CV_LOAD_IMAGE_GRAYSCALE);
		var letter = HighGui.imread("letter.jpg", HighGui.CV_LOAD_IMAGE_GRAYSCALE);
		var match = Mat.create();
		ImgProc.matchTemplate(captcha, letter, match, ImgProc.TM_SQDIFF);
		var r = Core.minMaxLoc(match);
		
		trace("minVal = " + r.minVal);
		trace("minLoc.x = " + r.minLoc.x);
		trace("minLoc.y = " + r.minLoc.y);
		
		this.assertTrue(true);
    }
}
