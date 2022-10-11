#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
       #include <sys/wait.h>

char* const param[]={"/user/bin/ls", "-s", "-l", (char*)NULL};
int main()
{
    int pid=fork();
    if (pid==0)
    {
        //execlp("ls", "ls", "-a", "-l", (char*)NULL);
        execv("/bin/ls", param);
        //execlp("/bin/ls","ls","-l", (char*)NULL);
        return 1;
    }
    int wstatus;
    wait(&wstatus);
    printf("finished %d \n", wstatus>>8);
    return 0;
}
