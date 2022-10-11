#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid;
    pid=fork();
    if (pid != 0)
    {
        //parinte
        if (pid % 2 != 0)
        {
            printf("parinte = lost");
            kill(getpid(), 9);//omorare 
            
        }
    }
    else
    {
        //fiu
        usleep(10);
        if (getpid() % 2 ==0)
            printf("fiu = fortune");
        
    }
    return 0;
}