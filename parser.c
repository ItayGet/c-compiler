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
	tbNode* t;

	if(!n->next) {
	 	t = tbNodeInit(&n->tok);
	 	cleanTlNode(n);
	 	return t;
	}

	t = parseParentheses(n);
	if(t)
		return t;

	for(int i = 0; i < sizeof_arr(orderOfOp); ++i) {
		t = parseOrderOfOp(n, i);

		if(t)
			return t;
	}
	
	
}

tbNode* parseOrderOfOp(tlNode* n, int order) {
	tlNode *root = n, *prev;
	int nestLevel = 0;

	while(n) {
		switch(n->tok.type) {
		case TTPARENTHESIS:
			switch(n->tok.c) {
				case '(':
					++nestLevel;
					break;
				case ')':
					--nestLevel;

					if(nestLevel < 0) {
						// Error: unmatched parentheses
						exit(-1);
					}
					break;
			}
			break;

		case TTOP:
			if(nestLevel == 0 && isCharInArray(orderOfOp[order], sizeof_arr(orderOfOp[order]), n->tok.c)) { 
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
			break;
		}

		prev = n;
		n = n->next;
	}

	return NULL;
}

tbNode* parseParentheses(tlNode* n) {
	if(n->tok.type != TTPARENTHESIS || n->tok.c != '(') { return NULL; }

	tlNode* prevToLast = n;
	while(prevToLast->next->next) {
		prevToLast = prevToLast->next;
	}
	
	token* lastTok = &prevToLast->next->tok;
	if(lastTok->type != TTPARENTHESIS || lastTok->c != ')') { return NULL; }

	tlNode* next = n->next;

	cleanTlNode(prevToLast->next);
	n->next = NULL;
	prevToLast->next = NULL;
	
	free(n);

	return parseExpression(next);
}
