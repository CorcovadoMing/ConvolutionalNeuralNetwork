#include "activation.h"

float relu(float input) {
	return (input > 0)? input : 0;
}

float none(float input) {
	return input;
}

