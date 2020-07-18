#include <stdlib.h>
#include <stdio.h>
#include "token.h"
#include "tlnode.h"

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
			addToken(curr, &t );
			curr = curr->next;
		} else {
			root = malloc(sizeof(token));
			curr = root;
			curr->tok = t;
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

void parseExpression(tlNode* n) {
	while(n->next) {
		tlNode *op = n->next, *arg2 = n->next->next;
		n->tok.integer = calcOperation(&n->tok, &op->tok, &arg2->tok);

		// Delete operation and second argument
		n->next = arg2->next;
		arg2->next = NULL;
		cleanTlNode(op);
	}
}

void main() {
	tlNode* n =  lexString("1+1 +5 -4 - 6 +7-5");
	printTlNode(n);
	parseExpression(n);

	printf("%d\n", n->tok.integer);

	cleanTlNode(n);
}
