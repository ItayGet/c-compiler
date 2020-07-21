#pragma once

#include "tbnode.h"
#include "tlnode.h"

tbNode* parseExpression(tlNode* n);
tbNode* parseOrderOfOp(tlNode* n, int order);
