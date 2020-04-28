#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
   
    pid_t pr1 = fork();
   // wait(NULL);
    pid_t pr2 = fork();
   // wait(NULL);
    pid_t pr3 = fork();
    wait(NULL);
    printf("[son] pid %d from [parent] pid %d\n", getpid(), getppid());
    return 1;
}