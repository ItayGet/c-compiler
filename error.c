#include "error.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void raiseError(const char* err) {
	fprintf(stderr, "ERROR: %s\n", err);
	exit(-1);
}
