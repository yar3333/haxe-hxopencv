#include "abstract.hpp"

////////////////////////////////////////////////////////////////////

value neko_AnnMlp_create(value layerSizes, value activateFunc, value fparam1, value fparam2)
{
    val_check_kind_or_fail(layerSizes, k_Mat);
    val_check_type_or_fail(activateFunc, int);
    val_check_type_or_fail(fparam1, number);
    val_check_type_or_fail(fparam2, number);

    return annMlpToValue(new CvANN_MLP(valueToMat(layerSizes), val_int(activateFunc), val_number(fparam1), val_number(fparam2)));
}
DEFINE_PRIM(neko_AnnMlp_create, 4);

//---------------------------------------------------

value neko_AnnMlp_train(value args[], int argc)
{
	if (argc != 7) failure("CvANN_MLP::train(): expected 7 arguments.");
	
	value annMlp		= args[0];
	value inputs		= args[1];
	value outputs		= args[2];
	value sampleWeights	= args[3];
	value sampleIdx		= args[4];
	value params		= args[5];
	value flags			= args[6];
	
	val_check_kind_or_fail(annMlp, k_AnnMlp);
    val_check_kind_or_fail(inputs, k_Mat);
    val_check_kind_or_fail(outputs, k_Mat);
    val_check_kind_or_fail(sampleWeights, k_Mat);
    if (!val_is_null(sampleIdx)) val_check_kind_or_fail(sampleIdx, k_Mat);
    if (!val_is_null(params)) val_check_type_or_fail(params, object);
    val_check_type_or_fail(flags, int);
    
	int iterations = valueToAnnMlp(annMlp)->train
	(
		  valueToMat(inputs)
		, valueToMat(outputs)
		, valueToMat(sampleWeights)
		, val_is_null(sampleIdx) ? Mat() : valueToMat(sampleIdx)
		, val_is_null(params) ? CvANN_MLP_TrainParams() : valueToAnnMlpTrainParams(params)
		, val_int(flags)
	);
    
	return alloc_int(iterations);
}
DEFINE_PRIM_MULT(neko_AnnMlp_train);

//---------------------------------------------------

value neko_AnnMlp_predict(value annMlp, value inputs, value outputs)
{
    val_check_kind_or_fail(annMlp, k_AnnMlp);
    val_check_kind_or_fail(inputs, k_Mat);
    val_check_kind_or_fail(outputs, k_Mat);

	valueToAnnMlp(annMlp)->predict(valueToMat(inputs), valueToMat(outputs));
	
	return val_null;
}
DEFINE_PRIM(neko_AnnMlp_predict, 3);

//---------------------------------------------------

value neko_AnnMlp_getLayerCount(value annMlp)
{
    val_check_kind_or_fail(annMlp, k_AnnMlp);
	int r = valueToAnnMlp(annMlp)->get_layer_count();
	return alloc_int(r);
}
DEFINE_PRIM(neko_AnnMlp_getLayerCount, 1);

//---------------------------------------------------

value neko_AnnMlp_getLayerSizes(value annMlp)
{
    val_check_kind_or_fail(annMlp, k_AnnMlp);
	Mat *r = new Mat(valueToAnnMlp(annMlp)->get_layer_sizes());
	return matToValue(*r);
}
DEFINE_PRIM(neko_AnnMlp_getLayerSizes, 1);

//---------------------------------------------------

value neko_AnnMlp_getWeights(value annMlp, value layer)
{
    val_check_kind_or_fail(annMlp, k_AnnMlp);
    val_check_type_or_fail(layer, int);
	
	CvANN_MLP *annMlpR = valueToAnnMlp(annMlp);
	int layerR = val_int(layer);
	
	Mat sizes(annMlpR->get_layer_sizes());
	int count = sizes.at<int>(layerR);
	double *weights = annMlpR->get_weights(layerR);
	value r = alloc_array(count);
	value *ptr = val_array_ptr(r);
	for (int i=0; i<count; i++, weights++, ptr++)
	{
		*ptr = alloc_float(*weights);
	}
	
	return r;
}
DEFINE_PRIM(neko_AnnMlp_getWeights, 2);

//---------------------------------------------------

value neko_AnnMlp_setWeights(value annMlp, value layer, value weights)
{
    val_check_kind_or_fail(annMlp, k_AnnMlp);
    val_check_type_or_fail(layer, int);
    val_check_type_or_fail(weights, array);
	
	value *srcWeights = val_array_ptr(weights);
	value *srcWeightsEnd = srcWeights + val_array_size(weights);
	double *dstWeights = valueToAnnMlp(annMlp)->get_weights(val_int(layer));
	
	while (srcWeights < srcWeightsEnd)
	{
		*dstWeights = val_number(*srcWeights);
		srcWeights++;
		dstWeights++;
	}
	
	return val_null;
}
DEFINE_PRIM(neko_AnnMlp_setWeights, 3);
