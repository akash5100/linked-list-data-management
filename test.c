#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef char* string;

void read(FILE* datafile);
void write(FILE* datafile);

void write(FILE* datafile)
{   
    int number;
    char name[MAX];
    char phone[MAX];
    char email[MAX];

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
        fprintf(datafile,"name,phone,email\n");
    }
    
    printf("enter number: ");
    scanf("%i",&number);
    getchar();

    printf("enter name: ");
    fgets(name,MAX,stdin);
    strtok(name, "\n");

    printf("enter phone: ");
    fgets(phone,MAX,stdin);
    strtok(phone, "\n");

    printf("enter email: ");
    fgets(email,MAX,stdin);
    strtok(email, "\n");

    fprintf(datafile,"%i,%s,%s,%s\n",number,name,phone,email);
    return;
}

void read(FILE* datafile)
{
    FILE* temp = datafile;
    char ch;
    printf("enter p or s: ");
    ch = getchar();

    switch (ch)
    {
        case 'p':      
            if (!temp)
            printf("Can't open file\n");
    
            else {
                // Here we have taken size of
            
                char buffer[MAX];
        
                int row = 0;
                int column = 0;
        
                while (fgets(buffer,MAX, temp)) 
                {
                    column = 0;
                    row++;

                    // To avoid printing of column
                    // names in file can be changed
                    // according to need
                    if (row == 1)
                        continue;

                    // Splitting the data
                    char* value = strtok(buffer, ",");
        
                    while (value) {

                        // Column 1
                        if (column == 0) {
                            puts("*-------------------------------");
                            printf("|ID:");
                        }
        
                        // Column 2
                        if (column == 1) {
                            printf("\n|\tName: ");
                        }
        
                        // Column 3
                        if (column == 2) {
                            printf("\n|\tPhone:");
                        }

                        // Column 4
                        if (column == 3) {
                            printf("\n|\tEmail:");
                        }
        
                        printf("%s", value);
                        value = strtok(NULL, ",");
                        column++;
                    }
                    printf("|\n");
                    puts("*-------------------------------\n ");
        
                }
            break;
        
        case 's': ;
            int id;
            printf("Enter the ID you want to print: ");
            scanf("%d",&id);
            id++;
            if (!temp)
            printf("Can't open file\n");
    
            else
            {
                char buffer[MAX];
        
                int row = 0;
                int column = 0;
        
                while (fgets(buffer,MAX, temp)) 
                {
                    column = 0;
                    row++;

                    // To avoid printing of column
                    // names in file can be changed
                    // according to need
                    if(row == 1)
                        continue;
                    else if (row == id)
                    {
                        // Splitting the data
                        char* value = strtok(buffer, ",");
                        while (value) 
                        {
                            // Column 1
                            if (column == 0) {
                                puts("*-------------------------------");
                                printf("|ID:");
                            }
            
                            // Column 2
                            if (column == 1) {
                                printf("\n|\tName: ");
                            }
            
                            // Column 3
                            if (column == 2) {
                                printf("\n|\tPhone:");
                            }

                            // Column 4
                            if (column == 3) {
                                printf("\n|\tEmail:");
                            }
            
                            printf("%s", value);
                            value = strtok(NULL, ",");
                            column++;
                        }
                        printf("|\n");
                        puts("*-------------------------------\n ");
                    }
                    else
                        continue;   
                }
            }
            break;
        default:
            break;
        }
    }
}

int main (void)
{
    FILE *datafile;

    //opening file
    datafile = fopen("file.csv","a+");

    //writing file
   // write(datafile);

    //readingfile
    read(datafile);

    //closing file
    fclose(datafile);
    printf("file saved successfully\n");

    return 0;
}

