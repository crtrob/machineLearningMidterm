// Filename: openfork.c
// Description: Opens a file, calls fork, and tests for concurrent write.
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
    // open an otherwise-useless text file
    int fop = open("openfork_file.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    // fork
    pid_t pid = fork();
    if (pid == 0)
    {
        // define message to write
        char cMsg[] = " Child write";
        // write it into file
        write(fop, cMsg, strlen(cMsg));
    } else if (pid < 0)
    {
        // error message for if fork failed
        fprintf(stderr, "fork failed\n");
    } else
    {
        // define message to write
        char pMsg[] = " Parent write";
        // write it into file
        write(fop, pMsg, strlen(pMsg));
        // wait for child process, just in case
        wait(NULL);
    }

    close(fop);
    return 0;
}