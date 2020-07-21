#include "parser.h"

#include <stdlib.h>
#include <stdbool.h>

static char orderOfOp[][2] = {
	{
		'+',
		'-'
	},
	{
		'*',
		'/'
	},
};

static bool isCharInArray(const char* arr, int len, char c) {
	for(int i = 0; i < len; ++i) {
		if(arr[i] == c)
			return true;
	}

	return false;
}

#define sizeof_arr(arr) sizeof(arr)/sizeof(arr[0])

tbNode* parseExpression(tlNode* n) {
	if(!n->next) {
	 	tbNode* t = tbNodeInit(&n->tok);
	 	cleanTlNode(n);
	 	return t;
	}

	for(int i = 0; i < sizeof_arr(orderOfOp); ++i) {
		tbNode* t = parseOrderOfOp(n, i);

		if(t)
			return t;
	}
	
	
}

tbNode* parseOrderOfOp(tlNode* n, int order) {
	tlNode *root = n, *prev;
	while(n) {
		bool isOp = n->tok.type == TTOP;
		if(isOp && isCharInArray(orderOfOp[order], sizeof_arr(orderOfOp[order]), n->tok.c)) { 
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

	return NULL;
}
