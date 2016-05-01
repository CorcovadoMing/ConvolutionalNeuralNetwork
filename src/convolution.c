#include <stdlib.h>
#include <math.h>
#include "convolution.h"
#include "image.h"

layer_t *convolution2D(layer_t *target, layer_t *kernel) {
	int kernel_size = kernel->feature[0]->size;
	int target_size = target->feature[0]->size;
	int result_size = target->feature[0]->size - kernel_size + 1;
	layer_t *result_layer = init_layer();

	for (int stack = 0; stack < kernel->size; stack += 1) {
    image_t *result = init_image2D(result_size);
		for(int i = 0; i < result_size; i += 1) {
			for(int j= 0; j < result_size; j += 1) {
				float sum = 0;
				for(int m = 0; m < kernel_size; m += 1) {
					for(int n = 0; n < kernel_size; n += 1) {
						for (int map = 0; map < target->size; map += 1) {
							sum += kernel->feature[stack]->element[0][m*kernel_size+n] * target->feature[0]->element[0][i*target_size+j+m*target_size+n];
						}
					}
				}
				result->element[0][i*result_size+j] = sum;
			}
		}
		add_feature(result_layer, result);
	}
	return result_layer;
}
