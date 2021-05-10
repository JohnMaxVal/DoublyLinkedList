#ifndef __DLL__
#define __DLL__

typedef struct doubly_linked_list_node {
  void *data;
  struct doubly_linked_list_node *left;
  struct doubly_linked_list_node *right;
} DoublyLinkedListNode;

typedef struct doubly_linked_list {
  DoublyLinkedListNode *node;
  int (*key_match)(void*, void*); // generic function for searching specified data
} DoublyLinkedList;

DoublyLinkedList*
create_dll_head();

// Last version

int
insert(DoublyLinkedList *dll, void *data);

void
delete(DoublyLinkedList *dll, void *data);

DoublyLinkedListNode *
search(DoublyLinkedList *dll, void *data);

void
register_key_match_callback(DoublyLinkedList* dll, int (*key_match)(void*, void*));

void*
search_by_key(DoublyLinkedList* dll, void* key);

#endif

// Old version
/*
int
insert_old(DoublyLinkedList *dll, void *data);

void
delete_old(DoublyLinkedList *dll, void *data);

DoublyLinkedListNode *
search_old(DoublyLinkedList *dll, void *data);
*/
