typedef struct ListNode_t
{
    struct ListNode_t *next;
    void *value;
} ListNode;

typedef struct
{
    ListNode *head;
    unsigned int length;
} List;

// Creating
extern List * random_list(unsigned int size);
extern ListNode * random_node(void);
extern List * list_from_array(void *array);
// Mutation
extern void delete_from_list(List *list, ListNode *node);
extern void delete_from_list_at_index(List *list, unsigned int index);
extern void free_node(ListNode *node);
extern void delete_list(List *list);
extern void append_to_list(List *list, ListNode *node);
extern void insert_to_list_at_index(List *list, ListNode *node, unsigned int index);
// Printing
extern void print_list(List *list); 
extern void print_node(ListNode *node);
// Aux
extern int * random_int(void);
