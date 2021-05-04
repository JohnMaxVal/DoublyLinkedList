#include "doubly_linked_list.h"
#include <stdlib.h>

DoublyLinkedList*
create_dll_head() {
  DoublyLinkedList* head_node = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
  head_node->node = NULL;
  return head_node;
}

int
add_node(DoublyLinkedList *dll, void *data) {
  if(!dll || !data) return -1;

  DoublyLinkedListNode *new_node = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;

  if(!dll->node) { // Get head
    dll->node = new_node;
    return 0;
  }

  DoublyLinkedListNode *head = dll->node; // Receive header pointer
  new_node->left = head;
  head->right = new_node;

  dll->node = new_node;
  return 1;
}

int
insert_before(DoublyLinkedList *dll, void* data) {
  if(!dll || !data) return -1;

  DoublyLinkedListNode *new_node = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;

  if(!dll->node) { // Add head
    dll->node = new_node;
    return 0;
  }

  DoublyLinkedListNode *head = dll->node;
  new_node->right = head;
  head->left = new_node;

  dll->node = new_node;
  return 1;
}

DoublyLinkedListNode *
get_node(DoublyLinkedListNode *head, int num) {
  DoublyLinkedListNode *current = head;

  while(current != NULL) {
    if((int)current->data == num)
      return current;
    current = current->right;
  }
  
  return current;
}
