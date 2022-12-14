#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#define BUFFER_SIZE 1000

int main(int argc, char *argv[])
{
    int n;
    int arr[2];
    char buffer[BUFFER_SIZE+1];
    char *data = "Hi Everyone!!";
    pipe(arr);
    write(arr[1], data, strlen(data));
    if((n = read(arr[0], buffer, BUFFER_SIZE)) >= 0)
    {
        buffer[n] = 0;
        printf("Read %d bytes from pipe '%s' \n", n, buffer);
    }
    else
        perror("read");
    exit(0);
}