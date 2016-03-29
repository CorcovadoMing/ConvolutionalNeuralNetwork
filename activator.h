#ifndef __ACTIVATOR__
#define __ACTIVATOR__

#include "layer.h"

#ifdef __cplusplus
extern "C" {
#endif

  typedef float (*activator_f) (float);
  layer_t *activator(layer_t *target, activator_f activator);

#ifdef __cplusplus
}
#endif

#endif
