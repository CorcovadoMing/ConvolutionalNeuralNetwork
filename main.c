#include <stdio.h>
#include "convolution.h"
#include "pooling.h"
#include "activation.h"
#include "activator.h"
#include "layer.h"
#include "net.h"

int main() {

	int i;
	printf("==== Initial status ====\n");
	image_t *test_cimage = init_image(8);
	for(i = 0; i < test_cimage->size*test_cimage->size; i += 1) {
		if (i%2)
			test_cimage->element[i] = i;
		else
			test_cimage->element[i] = -i;
	}
	kernel_t *test_kernel = init_kernel(3);
	for(i = 0; i < test_kernel->size*test_kernel->size; i += 1) {
		test_kernel->element[i] = (i%3)+1;
	}

	printf("Images:\n");
	layer_t *input_layer = init_layer();
	add_feature(input_layer, test_cimage);
	printlayer(input_layer);
	printf("\n");

	printf("Kernels:\n");
	layer_t *kernel_layer = init_layer();
	add_feature(kernel_layer, test_kernel);
	printlayer(kernel_layer);
	printf("\n");
	
	printf("==== Test convolution ====\n");
	layer_t *result_clayer = convolution(input_layer, kernel_layer);
	printlayer(result_clayer);

	printf("==== Test activator function ====\n");
	//image_t *result_aimage = activator(result_cimage, relu);
	//printmap(result_aimage);

	printf("==== Test pooling ====\n");
	//int pooling_factor = 3;
	//image_t *result_pimage = max_pooling(result_aimage, pooling_factor);
	//printmap(result_pimage);

	return 0;
}
