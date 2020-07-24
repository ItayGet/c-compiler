#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include "token.h"
#include "tlnode.h"
#include "tbnode.h"
#include "lexer.h"
#include "parser.h"

void raiseError(const char* err) {
	fprintf(stderr, err);
	exit(-1);
}

void main() {
	tlNode* n =  lexString("15555555*(2 + 3)/ 4 + 1");
	printTlNode(n);

	tbNode* t = parseExpression(n);
	tlNode* inOrder = tbNodeInorder(t);

	printf("\n");
	printTlNode(inOrder);

	cleanTlNode(inOrder);
	cleanTbNode(t);
}
