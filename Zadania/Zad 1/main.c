#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1


int main(int argc, char *argv[])
{
    int input_fd, output_fd;
    ssize_t ret_in, ret_out;
    char buffer[BUF_SIZE];

    //argv[1]="test";
    char nazwa[5000];
    strcat(nazwa, argv[1]);
    strcat(nazwa, ".red");
    //printf(nazwa);
    input_fd = open(argv[1], O_RDONLY);
    output_fd = open(nazwa, O_WRONLY | O_CREAT, 0644);


    while((ret_in = read(input_fd, &buffer, BUF_SIZE)) > 0)
    {
        lseek(input_fd, 2, SEEK_CUR);
        ret_out = write(output_fd, &buffer, (ssize_t) ret_in);
    }


    return 0;
}
