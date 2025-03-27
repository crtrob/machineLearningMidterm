// Filename: roberts_closh.cpp
// Description: barebones clone shell for linux designed to run a program 1 to 9 times in parallel or sequentially
// Author: Carter Roberts
// Instructor: Omar EL Khatib
// File Created: 3/26/2025 (MM/DD/YYYY)
// File Modified: 3/26/2025 (MM/DD/YYYY)

#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main()
{
    // holds program's absolute path directory
    char path[255];
    // holds amount of times program is ran
    int ran_times;
    // holds mode of running 
    char mode;

    while (true)
    {
        // prompt for absolute path directory
        cout << "closh> ";
        // get absolute path directory from input
        cin >> path;
        // shut down the shell if 'exit' is entered
        if (strcmp(path, "exit") == 0)
            break;
        // prompt for amount of times program is ran
        cout << "count> ";
        // get amount of times program is ran from input 
        cin >> ran_times;
        // keep input loop while invalid entry
        while (ran_times > 9 || ran_times < 1)
        {
            cout << "Invalid count, must be 1-9." << endl;
            cout << "count> ";
            cin >> ran_times;
        }
        // prompt/get mode of running, keep input loop while invalid entry
        bool isValid = false;
        while (!isValid)
        {
            cout << "[p]arallel or [s]equential> ";
            cin >> mode;
            if (mode == 'p' || mode == 's')
                isValid = true;
            if (!isValid) 
                cout << "Invalid mode, must be p or s." << endl;
        }

        // either run parallel or sequential
        if (mode == 'p')
        {
            // this will repeat as many times as times ran variable
            for (int i = 0; i < ran_times; i++)
            {
                // fork into child and parent
                pid_t pid = fork();
                // if fork fails or if process is a child
                if (pid < 0)
                {
                    // print error message and quit with error value
                    cout << "Error forking." << endl;
                    return 1;
                } else if (pid == 0)
                {
                    // set up execvp
                    char *myargs[3] = {path, NULL};
                    // execute program
                    execvp(myargs[0], myargs);
                    // this should not print
                    cout << "if this prints, there's a problem" << endl;
                }
                // parent doesn't wait since it's parallel
            }
        } else if (mode == 's')
        {
            // this will repeat as many times as times ran variable
            for (int i = 0; i < ran_times; i++)
            {
                // fork into child and parent
                pid_t pid = fork();
                // if fork fails or if process is a child
                if (pid < 0)
                {
                    // print error message and quit with error value
                    cout << "Error forking." << endl;
                    return 1;
                } else if (pid == 0)
                {
                    // set up execvp
                    char *myargs[3] = {path, NULL};
                    // execute program
                    execvp(myargs[0], myargs);
                    // this should not print
                    cout << "if this prints, there's a problem" << endl;
                } else 
                {
                    // wait for child process to terminate
                    waitpid(pid, NULL, 0);
                }
            }
        } else 
        {
            // print error message and quit with error value
            cout << "how? this shouldn't happen" << endl;
            return 1;
        }
    }

    return 0;
}