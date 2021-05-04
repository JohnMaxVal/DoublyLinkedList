typedef struct doubly_linked_list_node {
  void *data;
  struct doubly_linked_list_node *left;
  struct doubly_linked_list_node *right;
} DoublyLinkedListNode;

typedef struct doubly_linked_list {
  DoublyLinkedListNode *node;
} DoublyLinkedList;

DoublyLinkedList*
create_dll_head();

int
insert_before(DoublyLinkedList *dll, void *data);

void
delete_node(DoublyLinkedList *dll, void *data);

DoublyLinkedListNode *
search_node(DoublyLinkedList *dll, void *data);
