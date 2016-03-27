#ifndef __ACTIVATOR__
#define __ACTIVATOR__

#ifdef __cplusplus
extern "C" {
#endif

#include "layer.h"

typedef float (*activator_f) (float);
layer_t *activator(layer_t *target, activator_f activator);

#ifdef __cplusplus
}
#endif

#endif
