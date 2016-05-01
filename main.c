#include <stdio.h>
#include "src/convolution.h"
#include "src/pooling.h"
#include "src/activation.h"
#include "src/activator.h"
#include "src/layer.h"
#include "src/print.h"
#include "src/net.h"

int main() {

	int i;
	printf("==== Initial status ====\n");
	image_t *test_cimage1 = init_image2D(5);
	for(i = 0; i < test_cimage1->size*test_cimage1->size; i += 1) {
		if (i%2)
			test_cimage1->element[0][i] = i;
		else
			test_cimage1->element[0][i] = -i;
	}

	image_t *test_cimage2 = init_image2D(5);
	for(i = 0; i < test_cimage2->size*test_cimage2->size; i += 1) {
		if (i%2)
			test_cimage2->element[0][i] = i;
		else
			test_cimage2->element[0][i] = -i;
	}


	kernel_t *test_kernel1 = init_kernel2D(3);
	for(i = 0; i < test_kernel1->size*test_kernel1->size; i += 1) {
		test_kernel1->element[0][i] = (i%3)+1;
	}

	kernel_t *test_kernel2 = init_kernel2D(3);
	for(i = 0; i < test_kernel2->size*test_kernel2->size; i += 1) {
		test_kernel2->element[0][i] = -1;
	}

	printf("Images:\n");
	layer_t *input_layer = init_layer();
	add_feature(input_layer, test_cimage1);
	add_feature(input_layer, test_cimage2);
	printlayer(input_layer);

	printf("Kernels:\n");
	layer_t *kernel_layer = init_layer();
	add_feature(kernel_layer, test_kernel1);
	add_feature(kernel_layer, test_kernel2);
	printlayer(kernel_layer);

	printf("\n");
	printf("==== Test convolution ====\n");
	printf("Convolution2D:\n");
	layer_t *result_clayer = convolution2D(input_layer, kernel_layer);
	printlayer(result_clayer);

	printf("\n");
	printf("==== Test activator function ====\n");
	layer_t *result_alayer = activator(result_clayer, relu);
	printlayer(result_alayer);

	printf("\n");
	printf("==== Test pooling ====\n");
	printf("Max Pooling:\n");
	layer_t *result_player = max_pooling(result_alayer, 3);
	printlayer(result_player);
	printf("Avg Pooling:\n");
	result_player = avg_pooling(result_alayer, 3);
	printlayer(result_player);
	printf("Min Pooling:\n");
	result_player = min_pooling(result_alayer, 3);
	printlayer(result_player);

  printf("=== Test image3D ===\n");
  image_t *image3d = init_image3D(3, 3);
  image3d->element[0][1] = 1;
  image3d->element[1][1] = 2;
  image3d->element[2][1] = 3;
  printmap(image3d);

  return 0;
}
