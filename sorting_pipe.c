#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int pipefd[2];

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        // Close write end of the pipe
        close(pipefd[1]);

        // Duplicate stdin with read end of the pipe
        dup2(pipefd[0], STDIN_FILENO);

        // Close unused file descriptors
        close(pipefd[0]);

        // Execute the sort command
        execlp("sort", "sort", "-n", (char *)NULL);

        // If execlp fails
        perror("execlp");
        exit(EXIT_FAILURE);
    } else { // Parent process
        // Close read end of the pipe
        close(pipefd[0]);

        // Duplicate stdout with write end of the pipe
        dup2(pipefd[1], STDOUT_FILENO);

        // Close unused file descriptors
        close(pipefd[1]);

        // Print a message before each line
        execlp("awk", "awk", "{print \"Data received through pipe\", $0}", argv[1], (char *)NULL);

        // If execlp fails
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}