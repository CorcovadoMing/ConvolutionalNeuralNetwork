#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "layer.h"

layer_t *init_layer() {
	layer_t *layer_alloc = (layer_t *)malloc(sizeof(layer_t));
	layer_alloc->size = 0;
	layer_alloc->capacity = 0;
	layer_alloc->feature = (container_t **)malloc(sizeof(container_t *));
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

void printlayer(layer_t *layer) {
	int i = 0;
	for (i = 0; i < layer->size; i += 1) {
		printf("*** Feature %d ***\n", i);
		printmap(layer->feature[i]);
	}
}
