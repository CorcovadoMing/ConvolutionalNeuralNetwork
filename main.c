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
	image_t *test_cimage1 = init_image(3);
	for(i = 0; i < test_cimage1->size*test_cimage1->size; i += 1) {
		if (i%2)
			test_cimage1->element[i] = i;
		else
			test_cimage1->element[i] = -i;
	}

	image_t *test_cimage2 = init_image(3);
	for(i = 0; i < test_cimage2->size*test_cimage2->size; i += 1) {
		if (i%2)
			test_cimage2->element[i] = i;
		else
			test_cimage2->element[i] = -i;
	}


	kernel_t *test_kernel1 = init_kernel(3);
	for(i = 0; i < test_kernel1->size*test_kernel1->size; i += 1) {
		test_kernel1->element[i] = (i%3)+1;
	}
	
	kernel_t *test_kernel2 = init_kernel(3);
	for(i = 0; i < test_kernel2->size*test_kernel2->size; i += 1) {
		test_kernel2->element[i] = -1;
	}

	printf("Images:\n");
	layer_t *input_layer = init_layer();
	add_feature(input_layer, test_cimage1);
	add_feature(input_layer, test_cimage2);
	printlayer(input_layer);
	printf("\n");

	printf("Kernels:\n");
	layer_t *kernel_layer = init_layer();
	add_feature(kernel_layer, test_kernel1);
	add_feature(kernel_layer, test_kernel2);
	printlayer(kernel_layer);
	printf("\n");
	
	printf("==== Test convolution ====\n");
	layer_t *result_clayer = convolution(input_layer, kernel_layer);
	printlayer(result_clayer);

	printf("==== Test activator function ====\n");
	layer_t *result_alayer = activator(result_clayer, relu);
	printlayer(result_alayer);

	printf("==== Test pooling ====\n");
	//int pooling_factor = 3;
	//image_t *result_pimage = max_pooling(result_aimage, pooling_factor);
	//printmap(result_pimage);

	return 0;
}
