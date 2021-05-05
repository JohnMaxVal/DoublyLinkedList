#include "doubly_linked_list.h"
#include <stdlib.h>

DoublyLinkedList*
create_dll_head() {
  DoublyLinkedList* head_node = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
  head_node->node = NULL;
  return head_node;
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

void
delete_node(DoublyLinkedList *dll, void *data) {
  DoublyLinkedListNode **head = &dll->node;
  DoublyLinkedListNode *delete = *head;
  /* DoublyLinkedListNode *head = dll->node; */
  /* DoublyLinkedListNode *delete = head; */
  
  while(delete != NULL && (int)delete->data != (int)data)
    delete = delete->right;

  if(!delete) return;
  
  DoublyLinkedListNode *left = delete->left;
  DoublyLinkedListNode *right = delete->right;

  if(*head == delete) {
    //head = head->right;
    *head = right;
  }

  if(left != NULL)
    left->right = right;
  if(right != NULL)
    right->left = left;

  free(delete);
}

DoublyLinkedListNode *
search_node(DoublyLinkedList *dll, void *data) {
  
  return NULL;
}
