#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    int fd[2] , i = 0;
    pipe(fd);

    pid_t child_readfile;
    child_readfile = fork();


    if(child_readfile == -1) {
        perror("fork");
        exit(1);
    }

    if(child_readfile == 0) {
       FILE *fl = fopen("./numbers.txt", "r");
       int numbers[100];
       int len = 0;
       while (!feof(fl)){
           fscanf( fl , "%d" , &numbers[len]);
           len++;
       } 
       
       len--;

    //    for (int i = 0 ; i < len ; i++){
    //        printf("%d \n", numbers[i]);
    //    }
        close(fd[0]);
        close(1);

        dup(fd[1]);
        write( 1 , numbers , len * 4);
        //write(1 , len , sizeof(len));

    } else {
        wait(NULL);

        int numbers[100];
        int sub2 = 0 , sub3 = 0;

        close(fd[1]);
        close(0);

        int n = read(fd[0] , numbers , sizeof(numbers));
       // int m = read (fd[0] , len , sizeof(len));
        // int len = n;

        for (int i = 0; i < n / 4; i++)
        {
            // printf("%d \n", numbers[i]);
            if (numbers[i] % 2 == 0) sub2++;
            if (numbers[i] % 3 == 0) sub3++; 
        }

        printf("%d\n%d", sub2 , sub3);
        
    }
    return 0;
}