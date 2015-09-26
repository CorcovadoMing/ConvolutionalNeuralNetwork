#ifndef __IMAGE_T__
#define __IMAGE_T__

#include "container.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef container_t image_t;
image_t *init_image(int size);

#ifdef __cplusplus
}
#endif

#endif
