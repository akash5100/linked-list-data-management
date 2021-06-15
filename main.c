#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "linked_list.h"

/*  READ ME
*
*
*   promt user until user enter Q (quit)
*   if a single char doesnt work then try same character twice
*   example:
*   enter: p (doesnt work)
*   enter: pp (will work) 
*
*
*/

int main(void)
{
    Node* head = NULL;
    char ch;
    
    while(true)
    {   
        puts(" -------------------------------");
        printf("|\t\t\t\t|\n|\tP to print all contact\t|\n|\tD to delete contact\t|\n|\tA to add new contact\t|\n|\tS to search contact\t|\n|\tM to modify or change contact\t|\n|\tQ to save and quit\t|\n");
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
            int number;
            char name[MAX];     /*contains name*/  
            char phone[MAX];    /*contains phone number*/
            char email[MAX];    /*contains email */
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

        case '\n':
            break;

        default:
            printf("\ninvalid input\n your input should be P, D, A, S, M or Q\n");
            getchar();  //get char to from user to continue
            break;
        }
    }

}