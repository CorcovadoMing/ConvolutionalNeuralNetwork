#include "layer.h"

void init(layer_t *layer) {
	layer->size = 0;
	layer->capacity = 0;
}

void add_feature(layer_t *layer, container_t *target) {
	if(!layer->size) {
		layer->feature = (container_t **)malloc(sizeof(container_t *));
		layer->feature[0] = target;
		layer->size = 1
		layer->capacity = 1;
	}
	else if(layer->size < layer->capacity) {
		layer->feature[layer->size] = target;
		layer->size += 1;
	}
	else {
		layer->feature = (container_t **)realloc(layer->feature, sizeof(contianer_t *)*layer->capacity*2);
		layer->feature[layer->size] = target;
		layer->size += 1;
		layer->capacity *= 2;
}

