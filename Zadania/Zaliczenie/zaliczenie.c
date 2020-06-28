#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    struct stat upr;
    pid_t pid;
    pid = fork();

    if(pid > 0)
    {
        int pid_status;
        pid_t pid_child = wait(&pid_status);

        if(WIFEXITED(pid_status))
        {
            printf("Master: %d\n", (int) getpid());
            printf("Program zakonczono ze statusem: %d\n", WEXITSTATUS(pid_status));
        }
    }

    else if(pid == 0)
    {

    char sciezka[200] = "/etc/";
    struct stat file;
    struct dirent *de;
    //argv[1]="test";
    mkdir("/home/s24541/2s-kozlowkski-a-24541/Zadania/Zaliczenie/Zaliczenie", 0744);
    FILE * uprawnienia;
    char sciezka2[200]="/home/s24541/2s-kozlowkski-a-24541/Zadania/Zaliczenie/Zaliczenie/";
    strcat(sciezka2, argv[1]);
    uprawnienia = fopen(sciezka2, "w");
    DIR *dr = opendir("/etc/");


    while ((de = readdir(dr)) != NULL)
    {
        if(de->d_type == DT_REG)
        {
            strcat(sciezka, de->d_name);

            //lstat(sciezka, &file);
            lstat(sciezka, &upr);
            fprintf(uprawnienia,"%s", de->d_name);
            fprintf(uprawnienia,"%s", "   ");
            printf("%s   %o   ",de->d_name, upr.st_mode);
            fprintf(uprawnienia,"%o  ", upr.st_mode);

            if(upr.st_mode & S_IRUSR)
            {
            printf("r");
            fprintf(uprawnienia, "r");
            }
            else
            {
            printf("-");
            fprintf(uprawnienia, "-");
            }

            if(upr.st_mode & S_IWUSR)
            {
            printf("w");
            fprintf(uprawnienia, "w");
            }
            else
            {
            printf("-");
            fprintf(uprawnienia, "-");
            }

            if(upr.st_mode & S_IXUSR)
            {
            printf("x");
            fprintf(uprawnienia, "x");
            }
            else
            {
            printf("-");
            fprintf(uprawnienia, "-");
            }

            if(upr.st_mode & S_IRGRP)
            {
            printf("r");
            fprintf(uprawnienia, "r");
            }
            else
            {
            printf("-");
            fprintf(uprawnienia, "-");
            }

            if(upr.st_mode & S_IWGRP)
            {
            printf("w");
            fprintf(uprawnienia, "w");
            }
            else
            {
            printf("-");
            fprintf(uprawnienia, "-");
            }

            if(upr.st_mode & S_IXGRP)
            {
            printf("x");
            fprintf(uprawnienia, "x");
            }
            else
            {
            printf("-");
            fprintf(uprawnienia, "-");
            }

            if(upr.st_mode & S_IROTH)
            {
            printf("r");
            fprintf(uprawnienia, "r");
            }
            else
            {
            printf("-");
            fprintf(uprawnienia, "-");
            }

            if(upr.st_mode & S_IWOTH)
            {
            printf("w");
            fprintf(uprawnienia, "w");
            }
            else
            {
            printf("-");
            fprintf(uprawnienia, "-");
            }

            if(upr.st_mode & S_IXOTH)
            {
            printf("x");
            fprintf(uprawnienia, "x");
            }
            else
            {
            printf("-");
            fprintf(uprawnienia, "-");
            }

            fprintf(uprawnienia,"\n");
            printf("\n");

        }
        strcpy(sciezka,"/etc/");
    }
    closedir(dr);

    printf("Slave : %d\n", (int) getpid());
    //_exit(0);

    }
    return 0;
}
