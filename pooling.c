#include <stdlib.h>
#include "pooling.h"

image_t *max_pooling(image_t *target, int factor) {
	image_t *result = (image_t*)malloc(sizeof(image_t));
	int result_size = target->size/factor;
	result->size = result_size;
	result->element = (float*)malloc(result_size*result_size*sizeof(float));
	
	int i = 0, j = 0, m = 0, n = 0;
	for(i = 0; i < result_size; i += 1) {
		for(j = 0; j < result_size; j += 1) {
			float max_element = -999;
			for(m = 0; m < factor; m += 1) {
				for(n = 0; n < factor; n += 1) {
					if (target->element[i*target->size*factor+j*factor+m*target->size+n] > max_element) {
						max_element = target->element[i*target->size*factor+j*factor+m*target->size+n];
					}
				}
			}
			result->element[i*result->size+j] = max_element;
		}
	}
	return result;
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

