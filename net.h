#ifndef __NET__
#define __NET__

#include "kernel.h"
#include "image.h"
#include <stdlib.h>

typedef struct {
	int image_capacity;
	int image_num;
	image_t **image;
} net_t;

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

#endif
