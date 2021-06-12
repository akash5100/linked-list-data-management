#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    struct node *next;
};

//signature
Node* createNode(int data);
Node* insert(int data,Node *head);
Node* DELETE(int data, Node *head);
void search(Node *head);
void Traverse(Node *head);
void destroy_ll(Node *head);


// create single node with the `next` pointer pointing `NULL` ✔
Node* createNode(int data)
{
    Node *temp= malloc(sizeof(Node));
    //check if pointer is null
    if (temp == NULL)
    {
      fprintf(stderr,"Error: memory allocation failed.\n");
      exit(1);
    }

    temp->data=data;
    temp->next=NULL;
    return temp; //returns a pointer to a node with data and NUll pointer
}


// insert node

Node* insert(int data,Node *head)
{
    if (head == NULL)
        return createNode(data);
        
    Node* temp = head;
    //make temp pointer point to end
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* temp2 = createNode(data);
    temp->next = temp2;
        
    return head;
}

//delete node
Node* DELETE(int data, Node *head)
{
    Node* temp = head;
    Node* temp2 = head;
    while (temp2->data < data)
    {
        temp2 = temp2->next;
        if (temp2->data != data)
        {
            temp = temp2;
        }
    }
    temp->next = temp2->next;
    return head;
}

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
    
}

//display the nodes upto `NULL` ✔
void Traverse(Node *head)
{
    Node *temp=head;
    while(temp->next!=NULL)
    {
        printf("->%d",temp->data);
        temp=temp->next;
    }
    printf("->%d\n",temp->data); //printing the last node
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
