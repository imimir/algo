#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

void push(Stack *stack, StackNode *node)
{
    append_to_list(stack, node);
}

StackNode * pop(Stack *stack)
{
    StackNode **curr = &stack->head;
    StackNode *entry = *curr;
    for (; *curr; curr = &entry->next, entry = *curr)
    {
        if (!entry->next)
        {
            *curr = NULL;
            stack->length--;
            break;
        }
    }

    return entry;
}
        
