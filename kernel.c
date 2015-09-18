#include <stdlib.h>
#include "kernel.h"

kernel_t *init_kernel(int size) {
	kernel_t *kernel_alloc = (kernel_t*)malloc(sizeof(kernel_t));
	kernel_alloc->size = size;
	kernel_alloc->element = (float*)malloc(size*size*sizeof(float));
	return kernel_alloc;
}
