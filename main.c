#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "linked_list.h"

/*  READ ME


*   promt user until user enter Q
*   if a single char doesnt work then try same character twice
*   example:
*   enter: p (doesnt work)
*   enter: pp (will work) 


*/

int main(void)
{
    Node* head = NULL;
    char ch;
    
    while(true)
    {   
        puts(" -------------------------------");
        printf("|\t\t\t\t|\n|\tP to print all contact\t|\n|\tD to delete contact\t|\n|\tA to add new contact\t|\n|\tQ to save and quit\t|\n");
        puts(" -------------------------------\nEnter: ");
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
            int number;        /*unique account number*/
            char name[20];     /*contains name*/  
            char phone[15];    /*contains phone number*/
            char email[20];    /*contains email */
            //***************************
            printf("\nNumber: ");
            scanf("%i",&number);
            
            printf("Name: ");
            scanf("%s",name);
            
            printf("Phone: ");
            scanf("%s",phone);

            printf("Email: ");
            scanf("%s",email);
            
            //***************************
            if (head == NULL)
            {
                head = createNode(number,name,phone,email);
            }
            else{
                insert(number,name,email,phone,head);
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
                DELETE(z,head);
                printf("\nID: %i Deleted successfully\n");
            }
            break;

        case 'q':
            printf("\nclosing...");
            return 0;
            break;

        case '\n':
            break;

        default:
            printf("\ninvalid input\n your input should be P, D, A or Q\n");
            getchar();  //get char to from user to continue
            break;
        }
    }

}