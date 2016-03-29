#include <stdlib.h>
#include <stdio.h>
#include "activator.h"
#include "image.h"

layer_t *activator(layer_t *target, activator_f activator) {
	layer_t *result_layer = init_layer();
	for (int stack = 0; stack < target->size; stack += 1) {
		image_t *result = init_image2D(target->feature[stack]->size);
		for(int i = 0; i < result->size*result->size; i += 1) {
			result->element[0][i] = activator(target->feature[stack]->element[0][i]);
		}
		add_feature(result_layer, result);
	}
	return result_layer;
}

