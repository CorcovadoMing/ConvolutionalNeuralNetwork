#include <stdlib.h>
#include <stdio.h>
#include "image.h"

image_t *init_image2D(int size) {
  return init_image3D(size, 1);
}

image_t *init_image3D(int size, int depth) {
	image_t *image_alloc = (image_t *)malloc(sizeof(image_t));
	image_alloc->size = size;
  image_alloc->depth = depth;
	image_alloc->element = (float **)malloc(sizeof(float *));
  for (int i = 0; i < depth; i += 1) {
    image_alloc->element[i] = (float *)malloc(size*size*sizeof(float));
  }
  return image_alloc;
}

void printmap(image_t *target) {
	for (int i = 0; i < target->size; i += 1) {
    for (int k = 0; k < target->depth; k += 1) { 
      for (int j = 0; j < target->size; j += 1) {
        printf("%f\t", target->element[k][i*target->size+j]);
      }
      if (target->depth > 1 && k < target->depth -1) {
        printf("|\t");
      }
    }
		printf("\n");
	}
}
