#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "linked_list.h"

struct node
{
    int number;        /*unique account number*/
    char name[20];     /*contains name*/  
    char phone[15];    /*contains phone number*/
    char email[20];    /*contains email address*/
    //int data;
    struct node *next; 
};
typedef struct node Node;

// create single node with the `next` pointer pointing `NULL` ✔
Node* createNode(int number,char* name,char* phone, char* email)
{
    Node *temp= malloc(sizeof(Node));
    //check if pointer is null
    if (temp == NULL)
    {
      fprintf(stderr,"Error: memory allocation failed.\n");
      exit(1);
    }

    temp->number = number;
    strcpy(temp->name,name);
    strcpy(temp->email,email);
    strcpy(temp->phone,phone);
    temp->next=NULL;
    return temp; //returns a pointer to a node with data and NUll pointer
}


// insert node

Node* insert(int number,char* name, char* email, char* phone,Node *head)
{
    if (head == NULL)
        return createNode(number,name,phone,email);
        
    Node* temp = head;
    //make temp pointer point to end
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* temp2 = createNode(number,name,phone,email);
    temp->next = temp2;

    return head;
}

//delete node

// not working 


Node* DELETE(int number, Node *head)
{
    Node* temp = head;
    Node* prev = NULL; 

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->number == number) {
        if (temp->next != NULL)
        {
            head = temp->next; // Changed head    
        }
        else
        {
            head = NULL;
            return head;
        }
        free(temp); // free old head
        return head;
    }

    while (temp->number != number)
    {
        if (temp->next == NULL)
            printf("ID not found\n");
        else{
            prev = temp;
            temp = temp->next;}
    }

    return head;
}
/*
//search a node ✔
void search(Node *head)
{
    Node *temp=head;
    int k=0,a;
    printf("what number you want to find\n");
    scanf("%d",&a);
    while(temp!=NULL)
    {
        if(temp->data == a)
        {
            k++;
        }
        temp=temp->next;
    }
    printf("entered list have %d %d\n",k,a);
    
}*/

//display the nodes upto `NULL` ✔
void Traverse(Node *head)
{
    Node *temp=head;
    while(temp->next!=NULL)
    {
        puts(" -------------------------------");
        printf("|ID:%i\t\t\t\t\n|\tName: %s\t\t\n|\tPhone: %s\t\n|\tEmail: %s\t\n|\t\t\t\t\n",temp->number,temp->name,temp->phone,temp->email);
        puts(" -------------------------------\n ");

        temp=temp->next;
    }
        puts(" -------------------------------");
        printf("|ID:%i\t\t\t\t\n|\tName: %s\t\t\n|\tPhone: %s\t\n|\tEmail: %s\t\n|\t\t\t\t\n",temp->number,temp->name,temp->phone,temp->email);
        puts(" -------------------------------\n ");
        getchar();
        //printing the last node
}

//free the dynamically allocated nodes ✔
void destroy_ll(Node *head)
{
    Node *temp=head;
    while(temp->next!=NULL)
    {
        head= head->next;
        free(temp);
        temp=head;
    }
    free(head);
}
