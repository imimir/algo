#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>

#include "list.h"

void free_node(ListNode *node)
{
    assert(node);
    free(node->value);
    free(node);
}

void delete_list(List *list)
{
    assert(list);
    ListNode *curr = list->head;
    while (curr)
    {
        ListNode *temp = curr;
        curr = temp->next;

        free_node(temp);
    }
    free(list);
}

void print_list(List *list)
{
    assert(list);
    ListNode *tail = list->head;
    while (tail != NULL)
    {
        print_node(tail);
        tail = tail->next;
    }
    printf("List length: %d\n", list->length);
}

int * random_int(void)
{
    int *value = malloc(sizeof(int));
    *value = rand() % 100;

    return value;
}

void print_node(ListNode *node)
{
    printf("Node at %p. Value is %d\n", node, *(int *)node->value);
}

List * random_list(unsigned int size)
{
    List *list = malloc(sizeof(List));
    ListNode *head = random_node();
    if (!head || !list)
    {
        return NULL;
    }

    list->head = head;
    ListNode *curr = head;
    for (int i = 1; i < size; i++)
    {
        ListNode *node = random_node();
        if (!node)
        {
            return NULL;
        }
        
        curr->next = node;
        curr = node;
    }
    list->length = size;

    return list;
}

ListNode * random_node(void)
{
    ListNode *node = malloc(sizeof(ListNode));
    if (node)
    {
        node->next = NULL;
        node->value = random_int();
    }
    else
    {
        printf("ERROR: Can't allocate memory for ListNode\n");
    }

    return node;
}

void append_to_list(List *list, ListNode *node)
{
    insert_to_list_at_index(list, node, list->length);
}

void insert_to_list_at_index(List *list, ListNode *node, unsigned int index)
{
    assert(list);
    assert(node);
    assert(index <= list->length);
        
    ListNode **curr = &list->head;
    ListNode *entry = *curr;
    int i = 0; 
    while (entry && i != index)
    {
        curr = &entry->next; 
        entry = *curr;
        i++;
    }
    *curr = node;
    node->next = entry;
    list->length++;
}

void delete_from_list(List *list, ListNode *node)
{
    assert(list);
    assert(node);

    ListNode **curr = &list->head;
    ListNode *entry = *curr;
    while (entry)
    {
        if (entry == node)
        {
            *curr = entry->next;
            free_node(entry);
            list->length--;
            break;
        }
        curr = &entry->next;
        entry = *curr;
    }
}

void  delete_from_list_at_index(List *list, unsigned int index)
{
    assert(list);
    assert(index <= list->length);

    ListNode **curr = &list->head;
    ListNode *entry = *curr;
        
    int i = 0; 
    while (entry && i != index)
    {
        curr = &entry->next;
        entry = *curr;
    }

    *curr = entry->next;
    free_node(entry);
    list->length--;
}

