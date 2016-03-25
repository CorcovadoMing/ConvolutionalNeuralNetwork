#ifndef __CONVOLUTION__
#define __CONVOLUTION__

#include "kernel.h"
#include "image.h"

#ifdef __cplusplus
extern "C" {
#endif

image_t *convolution(image_t *target, kernel_t *kernel);

#ifdef __cplusplus
}
#endif

#endif
