#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

   
    pid = fork();

    if (pid < 0) {
        
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        
        printf("Child process: PID = %d\n", getpid());

        
        execl("/bin/ls", "ls", NULL);

        
        perror("execl failed");
        exit(1);
    }
    else {
        
        printf("Parent process: PID = %d, waiting for child to complete...\n", getpid());
        wait(NULL);

        printf("Child process finished.\n");
    }

    return 0;
}