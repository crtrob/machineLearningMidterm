// Filename: outputclose.c
// Description: forks, closes stdout_fileno for child, then child tries to printf; should error
// Author: Carter Roberts
// Instructor: Omar EL Khatib
// File Created: 3/25/2025 (MM/DD/YYYY)
// File Modified: 3/25/2025 (MM/DD/YYYY)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    // perform fork
    pid_t pid = fork();
    if (pid < 0)
    {
        // failure case, print error and go
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (pid == 0)
    {
        // close standard output for child
        close(STDOUT_FILENO);
        // this should fail to print
        printf("I love to eat poop");
    } else
    {
        // doesn't really matter that child closes stdout_fileno for parent
        printf("superfluous parent message\n");
    }

    return 0;
}
