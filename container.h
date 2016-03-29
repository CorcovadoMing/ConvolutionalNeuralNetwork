#ifndef __CONTAINER_T__
#define __CONTAINER_T__

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct {
	  int size;
	  float *element;
  } container_t;

  typedef struct {
    int size;
    int depth;
    float **element;
  } container3D_t

#ifdef __cplusplus
}
#endif

#endif
