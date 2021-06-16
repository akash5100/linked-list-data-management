#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef char* string;

int main (void)
{
    char name[MAX];
    char phone[MAX];
    char email[MAX];
    FILE *datafile;

    datafile = fopen("file.csv","a+");

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
    
    printf("enter name: ");
    fgets(name,MAX,stdin);
    strtok(name, "\n");

    printf("enter phone: ");
    fgets(phone,MAX,stdin);
    strtok(phone, "\n");

    printf("enter email: ");
    fgets(email,MAX,stdin);
    strtok(email, "\n");

    fprintf(datafile,"%s,%s,%s\n",name,phone,email);
    

    fclose(datafile);

    printf("file saved successfully\n");

    return 0;
}

