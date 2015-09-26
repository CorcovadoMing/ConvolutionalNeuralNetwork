#ifndef __CONVOLUTION__
#define __CONVOLUTION__

#include "kernel.h"
#include "image.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef float (* activator_f)(float);
image_t *convolution(image_t *target, kernel_t *kernel, activator_f activator);

#ifdef __cplusplus
}
#endif

#endif
