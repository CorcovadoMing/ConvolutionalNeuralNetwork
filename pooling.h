#ifndef __POOLING__
#define __POOLING__

#include "layer.h"

#ifdef __cplusplus
extern "C" {
#endif

layer_t *max_pooling(layer_t *target, int factor);
layer_t *avg_pooling(layer_t *target, int factor);
layer_t *min_pooling(layer_t *target, int factor);

#ifdef __cplusplus
}
#endif

#endif
