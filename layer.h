#ifndef __LAYER_T__
#define __LAYER_T__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	int size;
	int capacity;
	container_t *feature;
} layer_t;

void init(layer_t *);
void add_feature(layer_t *, container_t *);

#ifdef __cplusplus
}
#endif

#endif
