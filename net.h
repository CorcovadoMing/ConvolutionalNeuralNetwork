#ifndef __NET__
#define __NET__

#include "kernel.h"
#include "image.h"
#include "convolution.h"

typedef struct {
	int image_capacity;
	int image_num;
	image_t **image;
} net_t;

#endif
