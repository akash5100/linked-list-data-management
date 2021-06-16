#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

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
Node* createNode(int number,char* name,char* phone, char* email,FILE* datafile)
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
    fprintf(datafile,"%d,%s,%s,%s\n",temp->number,temp->name,temp->phone,temp->email);

    return temp; //returns a pointer to a node with data and NUll pointer
}


// insert node

Node* insert(int number,char* name, char* email, char* phone,Node *head,FILE* datafile)
{
    if (head == NULL)
        return createNode(number,name,phone,email,datafile);
        
    Node* temp = head;
    //make temp pointer point to end
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* temp2 = createNode(number,name,phone,email,datafile);
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
        else // if only 1 node, (if head->next == null) , then return null
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
            {   //if id not found in any node
                printf("ID not found\n");
            }
        else
            {
                prev = temp;
                temp = temp->next;
            }
    }
    //after above loop temp pointing our target, but double check using "if"
    if (temp->number == number)
    {
        prev->next = temp->next;
        return head;
    }
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
        printf("|ID:%i\n|\tName: %s\n|\tPhone: %s\n|\tEmail: %s\n|\n",temp->number,temp->name,temp->phone,temp->email);
        puts("*-------------------------------\n ");
        temp=temp->next;
    }
        puts("*-------------------------------");
        printf("|ID:%i\n|\tName: %s\n|\tPhone: %s\n|\tEmail: %s\n|\n",temp->number,temp->name,temp->phone,temp->email);
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


//promt with file handling
int promt_user_two(void)
{
    Node* head = NULL;
    char ch;

    /*  starting file pointer   */
    FILE *datafile = fopen("file.csv","a+");


    if (datafile == NULL)
    {
        printf("unable to create file.\n");
        exit(1);
    }

    //setting seek to starting of file '0'
    fseek(datafile,0, SEEK_END);
    //getting size of file in size using ftell which returns size of file 'int'
    int size = ftell(datafile);
    if (size == 0)
    {
        fprintf(datafile,"id,name,phone,email\n");
    }



    //promt user
    while(true)
    {   
        //display main menu
        puts(" ----------------------------------------");
        printf("|\t\t\t\t\t|\n|\tP to print all contact\t\t|\n|\tD to delete contact\t\t|\n|\tA to add new contact\t\t|\n|\tS to search contact\t\t|\n|\tM to modify or change contact\t|\n|\tQ to save and quit\t\t|\n");
        puts(" ----------------------------------------\nEnter: ");
        ch = tolower(getchar());
        getchar(); // eat the trailing newline

        switch (ch)
        {
        case 'p':
            if (head == NULL){
                printf("Sorry, 0 contact found\n");
                getchar();  //get char to from user to continue
            }
            else{
                Traverse(head);
            }
            break;
        
        case 'a': ;
            int number;
            char name[MAX];     /*contains name*/  
            char phone[MAX];    /*contains phone number*/
            char email[MAX];    /*contains email */
            //***************************//
            
            //getchar();
            printf("Name: ");
            fgets(name,MAX, stdin);
            strtok(name, "\n"); //removing new line due to fgets

            fflush(stdin);
            printf("Phone: ");
            fgets(phone,MAX, stdin);
            strtok(phone, "\n");
    
            fflush(stdin);
            printf("Email: ");
            fgets(email,MAX, stdin);
            strtok(email, "\n");
            
            //***************************
            if (head == NULL)
            {   
                number = 1;
                head = createNode(number,name,phone,email,datafile);
                
            }
            else{

                number = generate_UI(head);
                head = insert(number,name,email,phone,head,datafile);
            }
            break;
        
        case 'd': ;
            int z;
            if (head == NULL)
            {
                printf("contact list empty.\n");
                getchar(); //get char to from user to continue
            }
            else
            {
                Traverse(head);
                printf("Enter ID number to delete: ");
                scanf("%i",&z);
                printf("\nID: %i Deleted successfully\n",z);
                head = DELETE(z,head);
            }
            break;

        case 'm':
            modifycontact(head);

        case 's':
            print_contact(head);
            break;

        case 'q':
            fclose(datafile);
            printf("\nclosing...");
            return 0;
            break;
        
        //this case fixes a bug
        case '\n':
            break;

        default:
            printf("\nInvalid input\n Your input should be P, D, A, S, M or Q.\n");
            getchar();  //get char to from user to continue
            break;
        }
    }
}


/*
//promt without file handling
int promt_user(void)
{
    Node* head = NULL;
    char ch;

    while(true)
    {   
        //display main menu
        puts(" ----------------------------------------");
        printf("|\t\t\t\t\t|\n|\tP to print all contact\t\t|\n|\tD to delete contact\t\t|\n|\tA to add new contact\t\t|\n|\tS to search contact\t\t|\n|\tM to modify or change contact\t|\n|\tQ to save and quit\t\t|\n");
        puts(" ----------------------------------------\nEnter: ");
        ch = tolower(getchar());
        getchar(); // eat the trailing newline

        switch (ch) 
        {
        case 'p':
            if (head == NULL){
                printf("Sorry, 0 contact found\n");
                getchar();  //get char to from user to continue
            }
            else{
                Traverse(head);
            }
            break;
        
        case 'a': ;
            int number;
            char name[MAX];     
            char phone[MAX];    
            char email[MAX];    
            //***************************
            
            //getchar();
            printf("Name: ");
            fgets(name,MAX, stdin);

            fflush(stdin);
            printf("Phone: ");
            fgets(phone,MAX, stdin);
    
            fflush(stdin);
            printf("Email: ");
            fgets(email,MAX, stdin);
            
            //***************************
            if (head == NULL)
            {
                number = 1;
                head = createNode(number,name,phone,email);
            }
            else{

                number = generate_UI(head);
                head = insert(number,name,email,phone,head);
            }
            break;
        
        case 'd': ;
            int z;
            if (head == NULL)
            {
                printf("contact list empty.\n");
                getchar(); //get char to from user to continue
            }
            else
            {
                Traverse(head);
                printf("Enter ID number to delete: ");
                scanf("%i",&z);
                printf("\nID: %i Deleted successfully\n",z);
                head = DELETE(z,head);
            }
            break;

        case 'm':
            modifycontact(head);

        case 's':
            print_contact(head);
            break;

        case 'q':
            printf("\nclosing...");
            return 0;
            break;
        
        //this case fixes a bug
        case '\n':
            break;

        default:
            printf("\nInvalid input\n Your input should be P, D, A, S, M or Q.\n");
            getchar();  //get char to from user to continue
            break;
        }
    }
}
*/
