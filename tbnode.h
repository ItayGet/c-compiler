#pragma once

#include "token.h"
#include "tlnode.h"
#include <stdbool.h>

typedef struct tbNode {
	token tok;
	struct tbNode *left, *right;
} tbNode;

tbNode* tbNodeInit(const token* tok);
tlNode* tbNodeInorder(const tbNode* t);
void cleanTbNode(tbNode* t, bool cleanInside);
