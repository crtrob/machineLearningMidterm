// Filename: hibyefork.c
// Description: forks, prints hello for child and goodbye for parent, forces child first
// Author: Carter Roberts
// Instructor: Omar EL Khatib
// File Created: 3/25/2025 (MM/DD/YYYY)
// File Modified: 3/25/2025 (MM/DD/YYYY)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
    // do the forking
    pid_t pid = fork();
    if (pid < 0)
    {
        // failure case, print error and go
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (pid == 0) 
    {
        // print hello
        printf("hello\n");
    } else
    {
        // wait for child, then print goodbye
        wait(NULL);
        printf("goodbye\n");
    }

    return 0;
}