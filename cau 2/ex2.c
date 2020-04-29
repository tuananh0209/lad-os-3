#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


void waitProcess(int n){
    for (int i = 0 ; i < n ; i++)
    wait(NULL);
}

int main()
{
    pid_t id1 = fork();
    pid_t id2 = fork();
    pid_t id3 = fork();

    // parent process
    if (id1 > 0 && id2 > 0 && id3 > 0)
    {
        waitProcess(7);
        printf("process A %d\n" , getpid());
    }

    // 1st child
    else if (id1 == 0 && id2 > 0 && id3 > 0){
        waitProcess(6);
        printf("process B pid %d child of %d \n", getpid(), getppid());
    }
    else if (id1 > 0 && id2 == 0 && id3 > 0)
    {
        waitProcess(5);
        printf("process C pid %d child of %d \n", getpid(), getppid());
    }
    else if (id1 > 0 && id2 > 0 && id3 == 0)
    {
        waitProcess(4);
        printf("process D pid %d child of %d \n", getpid(), getppid());
    }
    else if (id1 == 0 && id2 == 0 && id3 > 0)
    {
        waitProcess(3);
        printf("process E pid %d child of %d \n", getpid(), getppid());
    }
    else if (id1 > 0 && id2 == 0 && id3 == 0)
    {
        waitProcess(2);
        printf("process G pid %d child of %d \n", getpid(), getppid());
    }
    else if (id1 == 0 && id2 > 0 && id3 == 0)
    {
        waitProcess(1);
        printf("process F pid %d child of %d \n", getpid(), getppid());
    }
    else if (id1 == 0 && id2 == 0 && id3 == 0)
    {
        waitProcess(0);
        printf("process I pid %d child of %d \n", getpid(), getppid());
    }

    return 0;
}
