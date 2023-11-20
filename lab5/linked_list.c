#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* insert(Node *p, int value){
  Node *newNode = (Node*)malloc(sizeof(Node));
   if(newNode == NULL) {
    printf("mem alloc error\n");
    return p;
  }
  newNode->value = value;
  newNode->next = p;

 return newNode;
}


void print_list(Node *p) {
    if (p == NULL) {
        return;
    }
    while (p != NULL) {
     if(p-> next ==NULL){
         printf("%d\n",p->value);

        printf("%d", p->value);
        p = p->next;
    }
  // printf("[empty list]\n");
}





Node* free_list(Node *p) {
    while (p != NULL) {
        Node *temp = p; 
        p = p->next; 
        free(temp); 
    }
    return NULL; 
}
Node* delete_node(Node* p, int value){
  Node* current = p;
  Node* prev = NULL;

  while(current != NULL && current-> value != value) {
   prev = current;
   current = current->next; 
 }
  if(current != NULL) {
   if (prev != NULL) {
      prev -> next = current->next;
    }else {
    p = current->next;
 }
  free(current);
}
  return p;
}

