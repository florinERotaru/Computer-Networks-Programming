
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
char *concat(const char* c1, const char* c2)
{
    char* res=calloc( strlen(c1) + strlen(c2)+1, sizeof(char));
    strcpy(res, c1);
    
    for (int j=0; j<strlen(c2); j++ )
    {
        res[j+strlen(c1)]=c2[j];
    }
    res[strlen(res)]='\0';
    return res;
    
}
//abc0 cba0
//res: abc0cba
int main(int argc, char* argv[])
{
    int fd1,fd2;
    if (-1 == (fd1=open(argv[1], O_RDONLY)))
    {
        printf("Couldn't find file");
        return 1;
    }
    char string1[100];
    int i=0;
    char p;
    while ( read(fd1, &p, sizeof(char)) && p != ' ')
    {
        string1[i]=p;
        i++;
    }
    
    printf("%s\n", string1);

    char * string2= calloc(100,1);
    int j=0;
    while ( read(fd1, &p, sizeof(char)) && p != ' ')
    {
        string2[j]=p;
        j++;
    }
    printf("%s\n", string2);

    if (-1==(fd2=open(argv[2], O_RDWR|O_TRUNC|O_CREAT, S_IRWXU)))
    {
        printf("Error at opening file");
        return 2;
    }
    //lseek(fd2, -1,SEEK_END);
    int size=strlen(concat(string1, string2));
    write(fd2, concat(string1, string2), size);


    return 0;
}