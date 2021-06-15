// declare every linked list function here

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#define MAX 30

typedef struct node Node;

//create node for linked list
Node* createNode(int number,char* name,char* phone, char* email);

//append node 
Node* insert(int number,char* name, char* email, char* phone,Node *head);

//delete node
Node* DELETE(int data, Node *head);

/*
* currently unused
//search node
void search(Node *head);
*/

//print particular contact
void print_contact(Node* head);

//generate UI for the user
int generate_UI(Node* head);

//print the whole node
void Traverse(Node *head);

//free the dynamic allocated 
void destroy_ll(Node *head);

//modify contact
void modifycontact(Node* head);

#endif