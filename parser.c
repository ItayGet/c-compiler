#include "parser.h"

#include <stdlib.h>

tbNode* parseExpression(tlNode* n) {
	if(!n->next) {
	 	tbNode* t = tbNodeInit(&n->tok);
	 	cleanTlNode(n);
	 	return t;
	}
	
	tlNode *root = n, *prev;
	while(n) {
		if(n->tok.type == TTOP) { 
			tbNode* t = tbNodeInit(&n->tok);
			
			// Left side
			prev->next = NULL;
			t->left = parseExpression(root);
			
			// Right side
			t->right = parseExpression(n->next);
			
			// Clean up operator
			free(n);
			
			return t;
		}
		prev = n;
		n = n->next;
	}
}
