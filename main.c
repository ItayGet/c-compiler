#include "stdio.h"
#include "tlnode.h"
#include "tbnode.h"
#include "lexer.h"
#include "parser.h"

void main() {
	tlNode* n =  lexString("1* 5555555*(2 + 3)/ 4 + 1");
	printTlNode(n);

	tbNode* t = parseExpression(n);
	tlNode* inOrder = tbNodeInorder(t);

	printf("\n");
	printTlNode(inOrder);

	cleanTlNode(inOrder);
	cleanTbNode(t);
}
