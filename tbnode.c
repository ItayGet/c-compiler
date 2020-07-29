#include "tbnode.h"

#include <stdlib.h>

tbNode* tbNodeInit(const token* tok) {
	tbNode* n = malloc(sizeof(tbNode));
	n->tok = *tok;
	return n;
}

tlNode* tbNodeInorder(const tbNode* t) {
	if (!t) return NULL;

	tlNode* n = tlNodeInit(&t->tok);
	n->next = tbNodeInorder(t->left);
	lastTlNode(n)->next = tbNodeInorder(t->right);

	return n;
}

void cleanTbNode(tbNode* t, bool cleanInside) {
	if(!t) return;

	cleanTbNode(t->left, cleanInside);
	cleanTbNode(t->right, cleanInside);
	
	if(cleanInside) { cleanToken(&t->tok); }

	free(t);
}
