#include "doubly_linked_list.h"
#include <stdlib.h>

DoublyLinkedList*
create_dll_head() {
  DoublyLinkedList* head_node = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
  head_node->node = NULL;
  return head_node;
}

DoublyLinkedListNode *
search(DoublyLinkedList *dll, void *x) {
  DoublyLinkedListNode *head = dll->node;

  while(head != NULL && (int)head->data != (int)x)
    head = head->right;
  
  return head;
}

int
insert(DoublyLinkedList *dll, void *data) {
  DoublyLinkedListNode *next = (DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
  next->data = data;
  next->left = NULL;
  next->right = dll->node;
  if(dll->node != NULL)
    dll->node->left = next;
  dll->node = next;
}

void
delete(DoublyLinkedList *dll, void *data) {
  DoublyLinkedListNode *delete = search(dll, data);

  if(delete->left != NULL)
    delete->left->right = delete->right;
  else
    dll->node = delete->right;

  if(delete->right != NULL)
    delete->right->left = delete->left;

  free(delete);
}

void
register_key_match_callback(DoublyLinkedList* dll, int (*key_match)(void*, void*)) {
  dll->key_match = key_match;
}

void*
search_by_key(DoublyLinkedList* dll, void* key) {
  if(dll == NULL || key == NULL) return NULL;

  DoublyLinkedListNode* head = dll->node;

  while(head) {
    if(dll->key_match(head->data, key) == 0)
      return head;
    head = head->right;
  }
  
  return head;
}

/*

int
insert_old(DoublyLinkedList *dll, void* data) {
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
delete_old(DoublyLinkedList *dll, void *data) {
  DoublyLinkedListNode **head = &dll->node;
  DoublyLinkedListNode *delete = *head;
  
  while(delete != NULL && (int)delete->data != (int)data)
    delete = delete->right;

  if(!delete) return;
  
  DoublyLinkedListNode *left = delete->left;
  DoublyLinkedListNode *right = delete->right;

  if(*head == delete)
    *head = right;

  if(left != NULL)
    left->right = right;
  if(right != NULL)
    right->left = left;

  free(delete);
}

DoublyLinkedListNode *
search_old(DoublyLinkedList *dll, void *data) {
  int search = (int)data;
  DoublyLinkedListNode *head = dll->node;

  if(!head || !search) return NULL;

  while(head != NULL && (int)head->data != search)
    head = head->right;
  
  return head;
}

*/
