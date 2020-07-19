#include "tlnode.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void addTlNode(tlNode* last, const token* tok) {
	last->next = malloc(sizeof(tlNode));
	last->next->tok = *tok;
	last->next->next = NULL;
}

void printTlNode(const tlNode* node) {
	const tlNode* curr = node;
	while(curr) {
		char val;
		switch(curr->tok.type) {
			case TTINTEGER:
				val = curr->tok.integer + '0';
				break;
			default:
				val = curr->tok.c;
		}

		printf("{ %d, %c }\n", curr->tok.type, val);
		curr = curr->next;
	}
}

void cleanTlNode(tlNode* node) {
	while(node) {
		tlNode* tmp = node->next;
		free(node);
		node = tmp;
	}
}

tlNode* lastTlNode(tlNode* node) {
	while(node->next)
		node = node->next;

	return node;
}

tlNode* tlNodeInit(const token* tok) {
	tlNode* n = malloc(sizeof(tlNode));
	n->tok = *tok;
	return n;
}
