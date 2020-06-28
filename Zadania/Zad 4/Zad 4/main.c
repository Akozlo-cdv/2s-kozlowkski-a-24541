#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 2000


int main(int argc, char *argv[])
{
    //Defincje
    struct stat file;
    struct dirent *de;
    char sciezka[100] = "/etc/sysconfig/";
    mkdir("/home/s24541/2s-kozlowkski-a-24541/Zadania/Zad 4/Results", 0777);
    FILE * foldery;
    FILE * uprawnienia;
    //Zapis folderow
    foldery = fopen("/home/s24541/2s-kozlowkski-a-24541/Zadania/Zad 4/Results/etc_dir.out", "w");
    DIR *dr = opendir("/etc/");

    while ((de = readdir(dr)) != NULL)
    {
        if(de->d_type == DT_DIR)
        {
            fprintf(foldery,"%s\n", de->d_name);
        }
    }
    closedir(dr);
    fclose(foldery);
    //Uprawnienia
    uprawnienia = fopen("/home/s24541/2s-kozlowkski-a-24541/Zadania/Zad 4/Results/sysconfig.out", "w");
    DIR *dr2 = opendir("/etc/sysconfig/");

    while ((de = readdir(dr2)) != NULL)
    {
        stat(strcat(sciezka, de->d_name), &file);
        if(de->d_type != DT_DIR && (file.st_mode & S_IWOTH) !=1 && (file.st_mode & S_IROTH) !=1 && (file.st_mode & S_IXOTH) !=1)
        {
            fprintf(uprawnienia,"%s\n", de->d_name);
        }
        strcpy(sciezka,"/etc/sysconfig/");
    }

    closedir(dr2);
    fclose(uprawnienia);

    return 0;
}
