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
		printf("{ %d, ", curr->tok.type);
		switch(curr->tok.type) {
			case TTINTEGER:
				printf("%d", curr->tok.integer);
				break;
			case TTIDENTIFIER:
				printf(curr->tok.str);
				break;
			default:
				printf("%c", curr->tok.c);
				break;
		}

		printf(" }\n");
		curr = curr->next;
	}
}

void cleanTlNode(tlNode* node, bool cleanInside) {
	while(node) {
		tlNode* tmp = node->next;

		if(cleanInside) { cleanToken(&node->tok); }

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
