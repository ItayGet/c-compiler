#include "lexer.h"

#include <stddef.h>

static int isDigit(char c) {
	return c >= '0' && c <= '9';
}

static int isOp(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
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
