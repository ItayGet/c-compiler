#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include "token.h"
#include "tlnode.h"
#include "tbnode.h"
#include "lexer.h"
#include "parser.h"

void main() {
	tlNode* n =  lexString("1+1+5-4-6+7-5");
	printTlNode(n);

	tbNode* t = parseExpression(n);
	tlNode* inOrder = tbNodeInorder(t);

	printf("\n");
	printTlNode(inOrder);

	cleanTlNode(inOrder);
	cleanTbNode(t);
}
