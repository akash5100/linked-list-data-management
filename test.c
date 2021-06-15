#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef char* string;

int main (void)
{
    char data[MAX];
    FILE *datafile;

    datafile = fopen("file.txt","a");

    if (datafile == NULL)
    {
        printf("unable to create file.\n");
        exit(1);
    }

    printf("enter the name: ");
    fgets(data,MAX,stdin);

    fputs(data, datafile);

    fclose(datafile);

    printf("file saved successfully\n");

    return 0;
}