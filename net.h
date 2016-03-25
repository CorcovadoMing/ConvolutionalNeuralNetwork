#ifndef __NET__
#define __NET__

#include "kernel.h"
#include "image.h"
#include "convolution.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
typedef struct {
	int image_capacity;
	int image_num;
	image_t **image;
} net_t;

void init(net_t *net);
void input(net_t *net, image_t *image);
typedef image_t *(* convolution_f)(image_t *, kernel_t *, activator_f);
void add_layer(net_t *net, convolution_f conv, kernel_t *kernel, activator_f activator);
*/

#ifdef __cplusplus
}
#endif

#endif
