#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    pid_t child_readfile;
    child_readfile = fork();

    int numbers[100];
    int len = 0;

    if(child_readfile == -1) {
        perror("fork");
        exit(1);
    }

    if(child_readfile == 0) {
        FILE *fp;
        fp = fopen("./numbers.txt" , "r");
        
        while (!feof(fp)){
            fscanf( fp, "%d" , &numbers[len]);
            len++;
        }
        len--;
        for (int i = 0 ; i < len  ; i++ ) printf("%d \n", numbers[i]);
        fclose(fp);
    } else {
        wait(NULL);
        
        int sud3 = 0;
        int sud2 = 0;
        for (int i = 0; i < len; i++)
            printf("%d \n", numbers[i]);
        printf("%d", len);
        for (int i = 0 ; i < len ; i ++) {
            if (numbers[i] % 2 == 0) {
                sud2++;
                printf("%d", numbers[i]);
            }
            else if (numbers[i] % 3 == 0) sud3++;
            printf("%d", numbers[i]);
        }

        printf("%d\n%d" , sud2 , sud3);
    }
    return 0;
}