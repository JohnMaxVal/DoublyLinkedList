#ifndef __DLL__
#define __DLL__

#define ITERATE_DLL_BEGIN(listptr, node_ptr)          \
  {						      \
    DoublyLinkedListNode* _node_ptr = NULL;           \
    node_ptr = listptr->node;                         \
    for(; node_ptr != NULL; node_ptr = _node_ptr) {   \
      _node_ptr = node_ptr->right;                    \

#define ITERATE_DLL_END }}

typedef struct doubly_linked_list_node {
  void *data;
  struct doubly_linked_list_node *left;
  struct doubly_linked_list_node *right;
} DoublyLinkedListNode;

typedef struct doubly_linked_list {
  DoublyLinkedListNode *node;
  int (*key_match)(void*, void*); // generic function for searching specified data
  int (*cmp)(void*, void*); // generic function for comparing data in DLL node
} DoublyLinkedList;

DoublyLinkedList*
create_dll_head();

// Last version

int
insert(DoublyLinkedList *dll, void* data);

void
delete(DoublyLinkedList *dll, void* data);

DoublyLinkedListNode *
search(DoublyLinkedList *dll, void* data);

void
register_key_match_callback(DoublyLinkedList* dll, int (*key_match)(void*, void*));

void*
search_by_key(DoublyLinkedList* dll, void* key);

void
register_compare_callback(DoublyLinkedList* dll, int (*cmp_fn)(void*, void*));

int
sort_insert(DoublyLinkedList* dll, void* data);

#endif
