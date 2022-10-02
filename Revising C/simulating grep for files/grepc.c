#include "stdio.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE* fileptr;
    fileptr=fopen(argv[1], "r");
    char*const pattern=calloc(sizeof(argv[2]), sizeof(char));
    strcpy(pattern, argv[2]);
    char line[200];
    while (!feof(fileptr))
    {
        fgets(line, 1000, fileptr);
        if (strstr(line, pattern))
            printf("%s", line);
    }
    fclose(fileptr);
    free(pattern);
}