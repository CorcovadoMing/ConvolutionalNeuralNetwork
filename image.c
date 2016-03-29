#include <stdlib.h>
#include <stdio.h>
#include "image.h"

image_t *init_image2D(int size) {
	image_t *image_alloc = (image_t *)malloc(sizeof(image_t));
	image_alloc->size = size;
  image_alloc->depth = 1;
	image_alloc->element = (float **)malloc(sizeof(float *));
  image_alloc->element[0] = (float *)malloc(size*size*sizeof(float));
	return image_alloc;
}

void printmap(image_t *target) {
	for (int i = 0; i < target->size; i += 1) {
		for (int j = 0; j < target->size; j += 1) {
			printf("%f\t", target->element[0][i*target->size+j]);
		}
		printf("\n");
	}
}
