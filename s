while(n->next) {
        tlNode *op = n->next, *arg2 = n->next >next;
        n->tok.integer = calcOperation(&n->tok, &op->tok, &arg2->tok);

        // Delete operation and second argument
        n->next = arg2->next;
        arg2->next = NULL;
        cleanTlNode(op);
}
