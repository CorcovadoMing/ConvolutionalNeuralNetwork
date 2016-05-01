#ifndef __LAYER_T__
#define __LAYER_T__

#include "container.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	int size;
	int capacity;
	container_t **feature;
} layer_t;

layer_t *init_layer();
void add_feature(layer_t *, container_t *);
void printlayer(layer_t *);

#ifdef __cplusplus
}
#endif

#endif
