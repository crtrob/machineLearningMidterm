// Filename: twoforks.c
// Description: forks twice and prints all child processes
// Author: Carter Roberts
// Instructor: Omar EL Khatib
// File Created: 3/25/2025 (MM/DD/YYYY)
// File Modified: 3/25/2025 (MM/DD/YYYY)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    // perform the first fork as in the code
    int pid = fork();
    if (pid == 0)
    {
        // print message for a child process
        printf("I am a child process\n");
    }
    
    // perform the second fork as in the code
    int pid2 = fork();
    if (pid2 == 0)
    {
        // print message for a child process
        printf("I am a child process\n");
    } 

    return 0;
}
