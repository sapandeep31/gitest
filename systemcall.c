#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int status;

    // Create a new process
    pid = fork();

    if (pid == -1)
    {
        // Error occurred
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // Child process
        printf("Child process (PID: %d)\n", getpid());

        // Execute a new program
        char *args[] = {"/bin/ls", "-l", NULL};
        execv(args[0], args);

        // execv only returns if there is an error
        perror("execv");
        exit(EXIT_FAILURE);
    }
    else
    {
        // Parent process
        printf("Parent process (PID: %d)\n", getpid());

        // Wait for the child process to complete
        if (wait(&status) == -1)
        {
            perror("wait");
            exit(EXIT_FAILURE);
        }

        // Check if the child process terminated normally
        if (WIFEXITED(status))
        {
            printf("Child exited with status: %d\n", WEXITSTATUS(status));
        }
        else
        {
            printf("Child did not exit normally\n");
        }
    }

    return 0;
}