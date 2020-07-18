#pragma once

#include <stddef.h>
#include <stdlib.h>
#include "token.h"

typedef struct tlNode {
	token tok;
	struct tlNode* next;
} tlNode;

void addToken(tlNode* last, const token* tok);
void printTlNode(const tlNode* node);
void cleanTlNode(tlNode* node);
