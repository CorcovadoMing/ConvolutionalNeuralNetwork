#ifndef __KERNEL_T__
#define __KERNEL_T__

#include "container.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef container_t kernel_t;
kernel_t *init_kernel2D(int size);

#ifdef __cplusplus
}
#endif

#endif
