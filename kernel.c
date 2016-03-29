#include <stdlib.h>
#include "kernel.h"

kernel_t *init_kernel2D(int size) {
	kernel_t *kernel_alloc = (kernel_t *)malloc(sizeof(kernel_t));
	kernel_alloc->size = size;
  kernel_alloc->depth = 1;
	kernel_alloc->element = (float **)malloc(sizeof(float *));
  kernel_alloc->element[0] = (float *)malloc(size*size*sizeof(float));

	int i = 0;
	for(i = 0; i < size*size; i += 1) {
    kernel_alloc->element[0][i] = (float)rand()/(float)(RAND_MAX);
	}

	return kernel_alloc;
}

