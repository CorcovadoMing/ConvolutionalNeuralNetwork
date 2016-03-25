#include <stdlib.h>
#include <math.h>
#include "convolution.h"

image_t *convolution(image_t *target, kernel_t *kernel) {
	image_t *result = (image_t *)malloc(sizeof(image_t));
	result->size = target->size - (kernel->size - 1);
	result->element = (float *)malloc(result->size*result->size*sizeof(float));

	int i = 0, j = 0, m = 0, n = 0;
	for(i = 0; i < result->size; i += 1) {
		for(j= 0; j < result->size; j += 1) {
			float sum = 0;
			for(m = 0; m < kernel->size; m += 1) {
				for(n = 0; n < kernel->size; n += 1) {
					sum += kernel->element[m*kernel->size+n]*target->element[i*target->size+j+m*target->size+n];
				}
			}
			result->element[i*result->size+j] = sum;
		}
	}
	
	return result;
}
