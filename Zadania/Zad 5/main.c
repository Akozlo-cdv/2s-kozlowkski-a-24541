#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>


int main()
{
    pid_t pid;
    //printf("Parent","%d", (int) getpid());
    pid = fork();
    int liczby[90];
    int licz_99=9;
    int status=1;
    FILE *f;

    if(pid > 0)
    {
        int pid_status;
        printf("Parent: %d\n", (int) getpid());
        pid_t pid_child = wait(&pid_status);

        if(WIFEXITED(pid_status))
        {
            printf("Normal execution. Exit status: %d\n", WEXITSTATUS(pid_status));
        }

    }


    else if(pid == 0)
    {

        f=fopen("file.txt","w");
            if (f == NULL)
            {
            status=0;
            _exit(1);
            }

        printf("Child : %d\n", (int) getpid());
        for (int t=0; t<=90; t++)
        {
            if(licz_99%3==0)
            {
            liczby[t]=licz_99;
            printf("%d\n",licz_99);
            fprintf(f, "%d\n", licz_99);
            }
            licz_99++;
        }
        fclose(f);
        _exit(0);
    }

    printf("Koniec\n");





    return 0;
}
