#pragma once

#include "token.h"

typedef struct tlNode {
	token tok;
	struct tlNode* next;
} tlNode;

void addTlNode(tlNode* last, const token* tok);
void printTlNode(const tlNode* node);
void cleanTlNode(tlNode* node);
tlNode* lastTlNode(tlNode* node);
tlNode* tlNodeInit(const token* tok); 
