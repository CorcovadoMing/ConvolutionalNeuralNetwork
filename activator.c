#include <stdlib.h>
#include "activator.h"
#include "image.h"

layer_t *activator(layer_t *target, activator_f activator) {

	layer_t *result_layer = init_layer();
	
	int stack = 0;
	for (stack = 0; stack < target->size; stack += 1) {
		image_t *result = (image_t *)malloc(sizeof(image_t));
		result->size = target->feature[stack]->size;
		result->element = (float *)malloc(result->size*result->size*sizeof(float));

		int i = 0;
		for(i = 0; i < result->size*result->size; i += 1) {
			result->element[i] = activator(target->feature[stack]->element[i]);
		}
		add_feature(result_layer, result);
	}
	return result_layer;
}

