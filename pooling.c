#include <stdlib.h>
#include "pooling.h"
#include "image.h"

layer_t *max_pooling(layer_t *target, int factor) {
	layer_t *result_layer = init_layer();
	
	int stack = 0;
	for (stack = 0; stack < target->size; stack += 1) {
		image_t *result = (image_t*)malloc(sizeof(image_t));
		int result_size = (target->feature[stack]->size)/factor;
		result->size = result_size;
		result->element = (float*)malloc(result_size*result_size*sizeof(float));
	
		int i = 0, j = 0, m = 0, n = 0;
		for(i = 0; i < result_size; i += 1) {
			for(j = 0; j < result_size; j += 1) {
				float max_element = -999;
				for(m = 0; m < factor; m += 1) {
					for(n = 0; n < factor; n += 1) {
						if (target->element[i*target->feature[stack]->size*factor+j*factor+m*target->feature[stack]->size+n] > max_element) {
							max_element = target->feature[stack]->element[i*target->feature[stack]->size*factor+j*factor+m*target->feature[stack]->size+n];
						}
					}
				}
				result->element[i*result->size+j] = max_element;
			}
		}
		add_feature(result_layer, result);
	}
	return result_layer;
}


image_t *avg_pooling(image_t *target, int factor) {
	image_t *result = (image_t*)malloc(sizeof(image_t));
	int result_size = target->size/factor;
	result->size = result_size;
	result->element = (float*)malloc(result_size*result_size*sizeof(float));
	
	int i = 0, j = 0, m = 0, n = 0;
	for(i = 0; i < result_size; i += 1) {
		for(j = 0; j < result_size; j += 1) {
			float sum = 0;
			for(m = 0; m < factor; m += 1) {
				for(n = 0; n < factor; n += 1) {
					sum += target->element[i*target->size*factor+j*factor+m*target->size+n];
				}
			}
			result->element[i*result->size+j] = sum;
		}
	}
	return result;
}


image_t *min_pooling(image_t *target, int factor) {
	image_t *result = (image_t*)malloc(sizeof(image_t));
	int result_size = target->size/factor;
	result->size = result_size;
	result->element = (float*)malloc(result_size*result_size*sizeof(float));
	
	int i = 0, j = 0, m = 0, n = 0;
	for(i = 0; i < result_size; i += 1) {
		for(j = 0; j < result_size; j += 1) {
			float min_element = 999;
			for(m = 0; m < factor; m += 1) {
				for(n = 0; n < factor; n += 1) {
					if (target->element[i*target->size*factor+j*factor+m*target->size+n] < min_element) {
						min_element = target->element[i*target->size*factor+j*factor+m*target->size+n];
					}
				}
			}
			result->element[i*result->size+j] = min_element;
		}
	}
	return result;
}

