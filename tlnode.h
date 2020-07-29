#pragma once

#include "token.h"
#include <stdbool.h>

typedef struct tlNode {
	token tok;
	struct tlNode* next;
} tlNode;

void addTlNode(tlNode* last, const token* tok);
void printTlNode(const tlNode* node);
void cleanTlNode(tlNode* node, bool cleanInside);
tlNode* lastTlNode(tlNode* node);
tlNode* tlNodeInit(const token* tok); 
