#include <stdlib.h>

#include "image.h"

image_t *init_image(int size) {
	image_t *image_alloc = (image_t*)malloc(sizeof(image_t));
	image_alloc->size = size;
	image_alloc->element = (float*)malloc(size*size*sizeof(float));
	return image_alloc;
}
