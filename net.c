#include <stdlib.h>
#include "net.h"

/*
void init(net_t *net) {
	net->image_capacity = 0;
	net->image_num = 0;
}

void input(net_t *net, image_t *image) {
	if(!net->image_num) {
		net->image = (image_t **)malloc(sizeof(image_t *));
		net->image[net->image_num] = image;
		net->image_num = 1;
		net->image_capacity = 1;
	}
	else if(net->image_num < net->image_capacity) {
		net->image[net->image_num] = image;
		net->image_num += 1;
	}
	else {
		net->image = (image_t **)realloc(net->image, sizeof(image_t *)*net->image_capacity*2);
		net->image[net->image_num] = image;
		net->image_num += 1;
		net->image_capacity *= 2;
	}
}

typedef image_t *(* convolution_f)(image_t *, kernel_t *, activator_f);

void add_layer(net_t *net, convolution_f conv, kernel_t *kernel, activator_f activator) {
	input(net, conv(net->image[net->image_num-1], kernel, activator));
}
*/
