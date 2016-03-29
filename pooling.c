#include <stdlib.h>
#include "pooling.h"
#include "image.h"

layer_t *max_pooling(layer_t *target, int factor) {
	layer_t *result_layer = init_layer();

	for (int stack = 0; stack < target->size; stack += 1) {
		int result_size = (target->feature[stack]->size)/factor;
		image_t *result = init_image2D(result_size);

		for(int i = 0; i < result_size; i += 1) {
			for(int j = 0; j < result_size; j += 1) {
				float max_element = -999;
				for(int m = 0; m < factor; m += 1) {
					for(int n = 0; n < factor; n += 1) {
						if (target->feature[stack]->element[0][i*target->feature[stack]->size*factor+j*factor+m*target->feature[stack]->size+n] > max_element) {
							max_element = target->feature[stack]->element[0][i*target->feature[stack]->size*factor+j*factor+m*target->feature[stack]->size+n];
						}
					}
				}
				result->element[0][i*result->size+j] = max_element;
			}
		}
		add_feature(result_layer, result);
	}
	return result_layer;
}


layer_t *avg_pooling(layer_t *target, int factor) {
	layer_t *result_layer = init_layer();

	for (int stack = 0; stack < target->size; stack += 1) {
		int result_size = (target->feature[stack]->size)/factor;
		image_t *result = init_image2D(result_size);

		for(int i = 0; i < result_size; i += 1) {
			for(int j = 0; j < result_size; j += 1) {
				float sum = 0;
				for(int m = 0; m < factor; m += 1) {
					for(int n = 0; n < factor; n += 1) {
						sum += target->feature[stack]->element[0][i*target->feature[stack]->size*factor+j*factor+m*target->feature[stack]->size+n];
					}
				}
				result->element[0][i*result->size+j] = sum;
			}
		}
		add_feature(result_layer, result);
	}
	return result_layer;
}


layer_t *min_pooling(layer_t *target, int factor) {
	layer_t *result_layer = init_layer();

	for (int stack = 0; stack < target->size; stack += 1) {
		int result_size = (target->feature[stack]->size)/factor;
		image_t *result = init_image2D(result_size);

		for(int i = 0; i < result_size; i += 1) {
			for(int j = 0; j < result_size; j += 1) {
				float min_element = 999;
				for(int m = 0; m < factor; m += 1) {
					for(int n = 0; n < factor; n += 1) {
						if (target->feature[stack]->element[0][i*target->feature[stack]->size*factor+j*factor+m*target->feature[stack]->size+n] < min_element) {
							min_element = target->feature[stack]->element[0][i*target->feature[stack]->size*factor+j*factor+m*target->feature[stack]->size+n];
						}
					}
				}
				result->element[0][i*result->size+j] = min_element;
			}
		}
		add_feature(result_layer, result);
	}
	return result_layer;
}

