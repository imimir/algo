#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

typedef struct HeapNode_t
{
    struct HeapNode_t *left;
    struct HeapNode_t *right;
    void *value;
} HeapNode;

typedef struct ListNode_t
{
    struct ListNode_t *next;
    void *value;
} ListNode;

// heap
HeapNode * random_heap(unsigned int size);
void delete_heap(HeapNode *heap);
void insert_to_heap(HeapNode *heap, HeapNode *node);
void delete_from_heap(HeapNode *heap, HeapNode *node);
HeapNode * pop(HeapNode *heap);
HeapNode * get_root(HeapNode *heap);
void print_heap(HeapNode *heap);
// linked list
ListNode * random_list(unsigned int size);
void delete_list(ListNode *list);
void append_to_list(ListNode *list, ListNode *node);
ListNode * insert_to_list_at_index(ListNode *list, ListNode *node, unsigned int index);
ListNode * delete_from_list(ListNode *list, ListNode *node);
ListNode * delete_from_list_at_index(ListNode *list, ListNode *node, unsigned int index);
void print_list(ListNode *list);

// stack


// aux
int * random_int(void);

int main()
{
    srand(time(NULL));

    ListNode *root = random_list(10);
    print_list(root);

    printf("--------------\n");

    ListNode *node = malloc(sizeof(ListNode));
    node->value = random_int();
    node->next = NULL;
    append_to_list(root, node);

    print_list(root);

    printf("--------------\n");
    
    ListNode *node_to_append = malloc(sizeof(ListNode));
    node_to_append->value = random_int();
    node_to_append->next = NULL;
    append_to_list(root, node_to_append);

    print_list(root);

    printf("--------------\n");

    ListNode *node_to_insert = malloc(sizeof(ListNode));
    node_to_insert->value = random_int();
    node_to_insert->next = NULL;
    //root = insert_to_list_at_index(root, node_to_insert, 0);
    print_list(root);

    delete_list(root);
    return 0;
}

// heap
void print_heap(HeapNode *heap)
{
    HeapNode *next = heap;
    while (next)
    {
        printf("HeapNode at: %p. value is %d", next, *(int *)next->value);
//        next = heap->next;
    }
}

int * random_int(void)
{
    int *value = malloc(sizeof(int));
    *value = rand() % 100;

    return value;
}
HeapNode * random_heap(unsigned int size)
{
    //HeapNode *root = malloc(sizeof(HeapNode));
    //root->next = null;
    return NULL;
}

// linked list
ListNode * random_list(unsigned int size)
{
    ListNode *root = malloc(sizeof(ListNode));
    root->next = NULL;
    root->value = random_int();

    ListNode *next = root;
    for (int i = 1; i < size; i++)
    {
        ListNode *node = malloc(sizeof(ListNode));
        node->next = NULL;
        node->value = random_int();

        next->next = node;
        next = node;
    }

    return root;
}

void print_list(ListNode *list)
{
    ListNode *next = list;
    int i = 1;
    while (next)
    {
        printf("%d. ListNode at: %p. value is: %d\n", i++, next, *(int *)next->value);
        next = next->next;
    }
}

void delete_list(ListNode *list)
{
    ListNode *next = list;
    while (next)
    {
        ListNode *temp = next;
        next = temp->next;

        free((int *)temp->value);
        free(temp);
    }
}

void append_to_list(ListNode *list, ListNode *node)
{
    ListNode *tail = list;
    while (true)
    {
        if (tail->next == NULL)
        {
            break;
        }
        tail = tail->next;
    }

    tail->next = node; 
}

ListNode * insert_to_list_at_index(ListNode *list, ListNode *node, unsigned int index)
{
    if (index == 0)
    {
        node->next = list;
        return node;
    }
        
    ListNode *next = list;
    int i = 0; 
    while (i < index - 1)
    {
       next = next->next; 
    }

    ListNode *temp = next->next;
    next->next = node;
    if (temp)
    {
        node->next = temp;
    }

    return list;
}


