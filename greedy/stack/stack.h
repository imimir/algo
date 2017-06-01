#ifndef RND_STACK_H
#define RND_STACK_H

#include "list.h"

typedef List Stack;
typedef ListNode StackNode;

StackNode * pop(Stack *stack);
void push(Stack *stack, StackNode *node);

#endif

