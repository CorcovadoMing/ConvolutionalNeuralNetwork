#include <stdio.h>
#include <stdlib.h>
#include "print.h"
#include "layer.h"

layer_t *init_layer() {
	layer_t *layer_alloc = (layer_t *)malloc(sizeof(layer_t));
	layer_alloc->size = 0;
	layer_alloc->capacity = 0;
  return layer_alloc;
}

void add_feature(layer_t *layer, container_t *target) {
	if(!layer->size) {
		layer->feature = (container_t **)malloc(sizeof(container_t *));
		layer->feature[0] = target;
		layer->size = 1;
		layer->capacity = 1;
	}
	else if(layer->size < layer->capacity) {
		layer->feature[layer->size] = target;
		layer->size += 1;
	}
	else {
    layer->feature = (container_t **)realloc(layer->feature, sizeof(container_t *)*layer->capacity*2);
		layer->feature[layer->size] = target;
		layer->size += 1;
		layer->capacity *= 2;
	}
}
