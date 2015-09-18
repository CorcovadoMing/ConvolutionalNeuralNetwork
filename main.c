#include <stdio.h>

#include "convolution.h"
#include "pooling.h"
#include "activation.h"

int main() {

	int i;

	/* Test Convolution */
	printf("==== Test convolution ====\n");
	image_t *test_cimage = init_image(5);
	for(i = 0; i < test_cimage->size*test_cimage->size; i += 1) {
		test_cimage->element[i] = i;
	}
	kernel_t *test_kernel = init_kernel(3);
	for(i = 0; i < test_kernel->size*test_kernel->size; i += 1) {
		test_kernel->element[i] = (i%3)+1;
	}
	
	image_t *result_cimage = convolution(test_cimage, test_kernel, relu);
	for (i = 0; i < result_cimage->size*result_cimage->size; i += 1) {
		printf("%f\n", result_cimage->element[i]);
	}


	/* Test pooling */
	printf("==== Test pooling ====\n");
	image_t *test_pimage = init_image(6);
	for(i = 0; i < test_pimage->size*test_pimage->size; i += 1) {
		test_pimage->element[i] = i+1;
	}

	int pooling_factor = 3;
	image_t *result_pimage = max_pooling(test_pimage, pooling_factor);
	for(i = 0; i < result_pimage->size*result_pimage->size; i += 1) {
		printf("%f\n", result_pimage->element[i]);
	}

	return 0;
}
