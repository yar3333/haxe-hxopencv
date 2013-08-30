package opencv2;

import neko.Lib;

private typedef _AnnMlp = { __AnnMlp:Dynamic };

typedef TermCriteria =
{
	var type : Int;
	var max_iter : Int;
	var epsilon : Float;
}

typedef TrainParams =
{
	var term_crit : TermCriteria;
	var train_method : Int;
	var param1 : Float;
	var param2 : Float;
}

class AnnMlp
{
    // activate func types
	public static inline var IDENTITY 		= 0;
	public static inline var SIGMOID_SYM	= 1;
	public static inline var GAUSSIAN 		= 2;
	
	// term criteria types
	public static inline var TERMCRIT_COUNT	= 1;
	public static inline var TERMCRIT_ITER	= TERMCRIT_COUNT;
	public static inline var TERMCRIT_EPS  	= 2;
	
    // available training flags
    public static inline var UPDATE_WEIGHTS 	= 1;
	public static inline var NO_INPUT_SCALE 	= 2;
	public static inline var NO_OUTPUT_SCALE	= 4;
	
	public var h(default, null) : _AnnMlp;
	
	public function new(h:_AnnMlp)
	{
		this.h = h;
	}
	
	public static function create(layerSizes:Mat, activateFunc=SIGMOID_SYM, fparam1=0.0, fparam2=0.0) : AnnMlp
	{
		return new AnnMlp(neko_AnnMlp_create(layerSizes.h, activateFunc, fparam1, fparam2));
	}
	private static var neko_AnnMlp_create = Lib.loadLazy("opencv", "neko_AnnMlp_create", 4);
	
	public function train(inputs:Mat, outputs:Mat, sampleWeights:Mat, ?sampleIdx:Mat, ?params:TrainParams, flags=0) : Int
	{
		return neko_AnnMlp_train(h, inputs.h, outputs.h, sampleWeights.h, sampleIdx!=null ? sampleIdx.h : null, Lib.haxeToNeko(params), flags);
	}
	private static var neko_AnnMlp_train = Lib.loadLazy("opencv", "neko_AnnMlp_train", -1);
	
	public function predict(inputs:Mat, outputs:Mat) : Void
	{
		neko_AnnMlp_predict(h, inputs.h, outputs.h);
	}
	private static var neko_AnnMlp_predict = Lib.loadLazy("opencv", "neko_AnnMlp_predict", 3);
	
	private function getLayerCount() : Int
	{
		return neko_AnnMlp_getLayerCount(h);
	}
	private static var neko_AnnMlp_getLayerCount = Lib.loadLazy("opencv", "neko_AnnMlp_getLayerCount", 1);
	
	private function getLayerSizes() : Int
	{
		return neko_AnnMlp_getLayerSizes(h);
	}
	private static var neko_AnnMlp_getLayerSizes = Lib.loadLazy("opencv", "neko_AnnMlp_getLayerSizes", 1);
	
	private function getWeights(layer:Int) : Array<Float>
	{
		return Lib.nekoToHaxe(neko_AnnMlp_getWeights(h, layer));
	}
	private static var neko_AnnMlp_getWeights = Lib.loadLazy("opencv", "neko_AnnMlp_getWeights", 2);
	
	private function setWeights(layer:Int, weights:Array<Float>) : Int
	{
		return neko_AnnMlp_setWeights(h, layer, Lib.haxeToNeko(weights));
	}
	private static var neko_AnnMlp_setWeights = Lib.loadLazy("opencv", "neko_AnnMlp_setWeights", 3);
}
