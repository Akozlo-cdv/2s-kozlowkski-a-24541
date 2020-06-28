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
        printf("Child : %d\n", (int) getpid());
        execl("/bin/ls","ls","-l", NULL);

        _exit(0);
    }

    printf("Koniec\n");





    return 0;
}
