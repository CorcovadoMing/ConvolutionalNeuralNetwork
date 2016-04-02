#include <stdio.h>
#include "print.h"

void printmap(image_t *target) {
	for (int i = 0; i < target->size; i += 1) {
    for (int k = 0; k < target->depth; k += 1) { 
      for (int j = 0; j < target->size; j += 1) {
        printf("%f\t", target->element[k][i*target->size+j]);
      }
      if (target->depth > 1 && k < target->depth -1) {
        printf("|\t");
      }
    }
		printf("\n");
	}
}

void printlayer(layer_t *layer) {
	for (int i = 0; i < layer->size; i += 1) {
		printf("*** Feature %d ***\n", i);
		printmap(layer->feature[i]);
	}
}
