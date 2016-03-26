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

	layer_t *input_layer = init_layer();
	add_feature(input_layer, test_cimage);
	printf("Image: \n");
	printmap(test_cimage);
	printf("Kernel: \n");
	printmap(test_kernel);
	
	printf("==== Test convolution ====\n");
	image_t *result_cimage = convolution(test_cimage, test_kernel);
	printmap(result_cimage);

	printf("==== Test activator function ====\n");
	image_t *result_aimage = activator(result_cimage, relu);
	printmap(result_aimage);

	printf("==== Test pooling ====\n");
	int pooling_factor = 3;
	image_t *result_pimage = max_pooling(result_aimage, pooling_factor);
	printmap(result_pimage);

	// API 9/20
/*
	net_t net;
	init(&net);
	input(&net, init_image(99));

	for(i = 0; i < 17; i += 1) {
		add_layer(&net, convolution, init_kernel(3), relu);
		printf("%d\t%d\t%d\n", net.image_num, net.image_capacity, net.image[i+1]->size);
	}


	printf("==== Test Randomize kernel init ====\n");
	kernel_t *random_kernel = init_kernel(3);
	for(i = 0; i < 9; i += 1) {
		printf("%f\n", random_kernel->element[i]);
	}
*/
	return 0;
}
