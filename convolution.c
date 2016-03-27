#include <stdlib.h>
#include <math.h>
#include "convolution.h"
#include "image.h"

layer_t *convolution2D(layer_t *target, layer_t *kernel) {
	int kernel_size = kernel->feature[0]->size;
	int target_size = target->feature[0]->size;
	int result_size = target->feature[0]->size - kernel_size + 1;
	layer_t *result_layer = init_layer();

	int stack = 0;
	for (stack = 0; stack < kernel->size; stack += 1) {
		image_t *result = (image_t *)malloc(sizeof(image_t));
		result->size = result_size;
		result->element = (float *)malloc(result_size*result_size*sizeof(float));
	
		int i = 0, j = 0, m = 0, n = 0, map = 0;
		for(i = 0; i < result_size; i += 1) {
			for(j= 0; j < result_size; j += 1) {
				float sum = 0;
				for(m = 0; m < kernel_size; m += 1) {
					for(n = 0; n < kernel_size; n += 1) {
						for (map = 0; map < target->size; map += 1) {
							sum += kernel->feature[stack]->element[m*kernel_size+n] * target->feature[0]->element[i*target_size+j+m*target_size+n];
						}
					}
				}
				result->element[i*result_size+j] = sum;
			}
		}
		add_feature(result_layer, result);
	}
	return result_layer;
}
