#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct node Node;

//create node for linked list
Node* createNode(int data);

//append node 
Node* insert(int data,Node *head);

//delete node
Node* DELETE(int data, Node *head);

//search node
void search(Node *head);

//print the whole node
void Traverse(Node *head);

//free the dynamic allocated 
void destroy_ll(Node *head);

#endif