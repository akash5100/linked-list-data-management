#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "linked_list.h"

struct node
{
    int number;        /*unique account number*/
    char name[MAX];     /*contains name*/  
    char phone[MAX];    /*contains phone number*/
    char email[MAX];    /*contains email address*/
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
    Node* temp = head;
    while(temp->next!=NULL)
    {
        puts("*-------------------------------");
        printf("|ID:%i\n|\tName: %s|\tPhone: %s|\tEmail: %s|\n",temp->number,temp->name,temp->phone,temp->email);
        puts("*-------------------------------\n ");
        temp=temp->next;
    }
        puts("*-------------------------------");
        printf("|ID:%i\n|\tName: %s|\tPhone: %s|\tEmail: %s|\n",temp->number,temp->name,temp->phone,temp->email);
        puts("*-------------------------------\n ");
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

// modify contact

void modifycontact(Node* head)   
{
    int record;
    Node* temp = head;
    Node* prev= NULL; 
    if(head == NULL)
    {
        puts("There are no contacts to modify!");
	    return;
    }
    
    Traverse(head);		/* show all records */
    printf("Enter contact ID to modify or change: ");
    scanf("%d",&record);  /*scan user input to record*/

    while (temp != NULL)
    {
        if (temp->number == record)
        {
            prev = temp;
            break;
        }
        temp = temp->next;
    }

    char name[MAX];     /*contains name*/  
    char phone[MAX];    /*contains phone number*/
    char email[MAX];    /*contains email */
    //***************************
    
    getchar();
    printf("Name: ");
    fgets(name,MAX, stdin);

    fflush(stdin);
    printf("Phone: ");
    fgets(phone,MAX, stdin);

    fflush(stdin);
    printf("Email: ");
    fgets(email,MAX, stdin);

    strcpy(temp->name,name);
    strcpy(temp->email,email);
    strcpy(temp->phone,phone);
    
    printf("contact changed successfully\n");
    return;
}

int findcontact(Node* head) /* find contact function*/
{
    char buff[30];
     
    if(head==NULL)
	{
        puts("There are no contacts to find!");
	    return 1;
    }
    
    printf("Enter contact name: ");
    fflush(stdin);/*clears any text from the input stream*/
    fgets(buff,MAX,stdin);
    
    //todo
    
    printf("contact %s was not found!\n",buff);
          return 1;
}


int generate_UI(Node* head)
{
    int number;

    Node* temp = head;
    Node* target = NULL; // target to point the last node
    while (temp != NULL)
    {
        target = temp;
        temp = temp->next;
    }
    number = target->number +1;
    
    return number;
}


void print_contact(Node* head)
{
    Node* temp=head;

    if (temp == NULL)
    {
        printf("0 contact found\n");
        getchar();
        return;
    }
    else
    {
        while (temp != NULL)
        {
            printf("-> %i",temp->number);
            temp = temp->next;
        }
        printf("\n\n");
        int ID;
        printf("Enter the ID you want to print: ");
        scanf("%d",&ID);
        
        temp = head;
        while(temp != NULL)
        {
            if (temp->number == ID)
            {
                puts("*-------------------------------");
                printf("|ID:%i\n|\tName: %s|\tPhone: %s|\tEmail: %s|\n",temp->number,temp->name,temp->phone,temp->email);
                puts("*-------------------------------\n ");
                getchar();
            }
            temp = temp->next;       
        }
    }
    return;
}