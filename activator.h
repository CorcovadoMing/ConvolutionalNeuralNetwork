#ifndef __ACTIVATOR__
#define __ACTIVATOR__

#ifdef __cplusplus
extern "C" {
#endif

#include "image.h"

typedef float (*activator_f) (float);
image_t *activator(image_t *target, activator_f activator);

#ifdef __cplusplus
}
#endif

#endif
