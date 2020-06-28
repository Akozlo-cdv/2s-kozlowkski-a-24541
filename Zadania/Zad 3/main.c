#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAXCHAR 4
int main(int argc, char *argv[])
{
    //argv[1]="test";
    FILE *fp;
    FILE *fp2;
    char str[MAXCHAR];
    char* filename = argv[1];

    char nazwa[5000];
    strcat(nazwa, argv[1]);
    strcat(nazwa, ".red");

    fp = fopen(filename, "r");
    fp2 = fopen(nazwa, "w");

    while (fgets(str, MAXCHAR, fp) != NULL)
    {
        printf("%c", str[0]);
        fprintf (fp2, "%c",str[0]);
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}
