#ifndef __POOLING__
#define __POOLING__

#include "image.h"

#ifdef __cplusplus
extern "C" {
#endif

image_t *max_pooling(image_t *target, int factor);
image_t *avg_pooling(image_t *target, int factor);


#ifdef __cplusplus
}
#endif

#endif
