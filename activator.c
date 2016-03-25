#include <stdlib.h>
#include "activator.h"

image_t *activator(image_t *target, activator_f activator) {
	image_t *result = (image_t *)malloc(sizeof(image_t));
	result->size = target->size;
	result->element = (float *)malloc(result->size*result->size*sizeof(float));


	int i = 0;
	for(i = 0; i < result->size*result->size; i += 1) {
		result->element[i] = activator(target->element[i]);
	}
	return result;
}

