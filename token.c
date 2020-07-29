#include "token.h"

#include <stdlib.h>

void cleanToken(token* tok) {
	switch(tok->type) {
	case TTIDENTIFIER:
		free(tok->str);
		break;
	}
}
