#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct Node{
   int value;
   struct Node* next;
}Node;


Node* insert(Node *p, int value);
	void print_list(Node *p);
	Node* free_list(Node *p);
	Node* delete_node(Node* p, int value);
#endif
