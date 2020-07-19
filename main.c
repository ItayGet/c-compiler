#include <stdlib.h>
#include <stdio.h>
#include "token.h"
#include "tlnode.h"
#include "tbnode.h"

int isDigit(char c) {
	return c >= '0' && c <= '9';
}

int isOp(char c) {
	return c == '+' || c == '-';
}

tlNode* lexString(const char* str) {
	tlNode* root = NULL;
	tlNode* curr;
	for(int i = 0; str[i] != '\0'; ++i) {
		token t;
		if(isDigit(str[i])) {
			t.type = TTINTEGER;
			t.integer = str[i]-'0';
		} else if (isOp(str[i])) {
			t.type = TTOP;
			t.c = str[i];
		} else {
			continue;
		}
		
		if(root) {
			addTlNode(curr, &t );
			curr = curr->next;
		} else {
			root = tlNodeInit(&t);
			curr = root;
			curr->next = NULL;
		}
	}
	return root;
}

int calcOperation(const token* a, const token* op, const token* b) {
	// Error in input
	if(a->type != b->type || a->type != TTINTEGER || op->type != TTOP) { exit(0); }

	switch(op->c) {
		case '-':
			return a->integer - b->integer;
		case '+':
		default:
			return a->integer + b->integer;
	}
}

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

void main() {
	tlNode* n =  lexString("1+1 +5 -4 - 6 +7-5");
	tbNode* t = parseExpression(n);
	tlNode* inOrder = tbNodeInorder(t);

	printTlNode(n);
	printf("\n");
	printTlNode(inOrder);

	cleanTlNode(inOrder);
	cleanTlNode(n);
	cleanTbNode(t);
}
