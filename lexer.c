#include "lexer.h"

#include <math.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

static bool isStartIdentifier(char c) {
	return (c >= 'a' && c <= 'z') ||
	       (c >= 'A' && c <= 'Z') ||
	       (c == '_');
}

static int getNum(const char* str, int* iref) {
	int num = 0, i;
	for(i = 0; str[i] != '\0'; ++i) {
		if(isDigit(str[i])) {
			num *= 10;
			num += (int)(str[i]-'0');
		} else {
			break;
		}
	}
	*iref += i-1;
	return num;
}

static char* getIdentifier(const char* str, int* iref) {
	int i;
	for(i = 0; str[i] != '\0'; ++i) {
		if(!isStartIdentifier(str[i]) && !isDigit(str[i])) {
			break;
		}
	}
	char* identifier = malloc(sizeof(char)*(i+1));
	memcpy(identifier, str, i*sizeof(char));
	identifier[i] = '\0';
	*iref += i-1;
	return identifier;
}

static bool isOp(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

static bool isParenthesis(char c) {
	return c == '(' || c == ')';
}

tlNode* lexString(const char* str) {
	tlNode* root = NULL;
	tlNode* curr;
	for(int i = 0; str[i] != '\0'; ++i) {
		token t;
		if(isStartIdentifier(str[i])) {
			t.type = TTIDENTIFIER;
			t.str = getIdentifier(str+i, &i);
		} else if(isDigit(str[i])) {
			t.type = TTINTEGER;
			t.integer = getNum(str+i, &i);
		} else if(isOp(str[i])) {
			t.type = TTOP;
			t.c = str[i];
		} else if(isParenthesis(str[i])) { 
			t.type = TTPARENTHESIS;
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
