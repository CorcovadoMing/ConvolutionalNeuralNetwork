#include <stdlib.h>
#include <stdio.h>
#include "image.h"

image_t *init_image(int size) {
	image_t *image_alloc = (image_t*)malloc(sizeof(image_t));
	image_alloc->size = size;
	image_alloc->element = (float*)malloc(size*size*sizeof(float));
	return image_alloc;
}

void print(image_t *target) {
	int i = 0, j = 0;
	for (i = 0; i < target->size; i += 1) {
		for (j = 0; j < target->size; j += 1) {
			printf("%f\t", target->element[i*target->size+j]);
		}
		printf("\n");
	}
}
