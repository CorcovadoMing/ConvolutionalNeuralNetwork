#ifndef __IMAGE_T__
#define __IMAGE_T__

#include "container.h"

#ifdef __cplusplus
extern "C" {
#endif

  typedef container_t image_t;
  image_t *init_image2D(int size);
  image_t *init_image3D(int size, int depth);

#ifdef __cplusplus
}
#endif

#endif
