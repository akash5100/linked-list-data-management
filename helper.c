#include "helper.h"

int main(void)
{
    Node* head = NULL;
    char ch;
    
    do
    {   
        printf("enter letter p,d,a,q: ");
        scanf("%c",&ch);
        switch (ch)
        {
        case 'p':
            if (head == NULL){
                printf("head is null\n");
            }
            else{
                Traverse(head);
            }
            break;
        
        case 'a': ;
            int t;
            printf("enter number to append: ");
            scanf("%i\n",&t);
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
            printf("enter number you want to delete");
            scanf("%i",&z);
            DELETE(z,head);
            break;

        case 'q':
            return 0;
            break;

        case '\n':
            break;

        default:
            printf("\ninvalid input\n");
            break;
        }
    } while (ch != 'q' || ch != 'Q');

    return 0;
}