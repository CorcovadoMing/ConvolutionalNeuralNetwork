#ifndef __CONVOLUTION__
#define __CONVOLUTION__

#include "kernel.h"
#include "layer.h"

#ifdef __cplusplus
extern "C" {
#endif

layer_t *convolution(layer_t *target, layer_t *kernel);

#ifdef __cplusplus
}
#endif

#endif
