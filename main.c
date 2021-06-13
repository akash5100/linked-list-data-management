#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "linked_list.h"


int main(void)
{
    Node* head = NULL;
    char ch;
    
    while(true)
    {   
        puts(" -------------------------------");
        printf("|Enter:\t\t\t\t|\n|\tP to print all contact\t|\n|\tD to delete contact\t|\n|\tA to add new contact\t|\n|\tQ to save and quit\t|\n");
        puts(" -------------------------------\nEnter: ");
        ch = tolower(getchar());
        getchar(); // eat the trailing newline

        switch (ch)
        {
        case 'p':
            if (head == NULL){
                printf("Sorry, 0 contact found\n");
            }
            else{
                Traverse(head);
            }
            break;
        
        case 'a': ;
            int t;
            printf("todo: ");
            scanf("%i",&t);
            if (head == NULL)
            {
                head = createNode(t);
            }
            else{
                insert(t,head);
            }
            break;
        
        case 'd': ;
            int z;
            if (head == NULL)
            {
                printf("contact list already empty.\n");
            }
            else
            {
                Traverse(head);
                printf("Enter key number to delete: ");
                scanf("%i",&z);
                DELETE(z,head);
            }
            break;

        case 'q':
            printf("\nclosing...");
            return 0;
            break;

        case '\n':
            break;

        default:
            printf("\ninvalid input\n your input should be Q, P, A or D\n");
            break;
        }
    }

}