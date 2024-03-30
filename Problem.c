#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parent_writes_child_reads() {
    int pipefd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];
    
    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        close(pipefd[0]); // Close the reading end in the parent
        const char *data = "Hello child!";
        write(pipefd[1], data, strlen(data));
        printf("Parent wrote: %s\n", data);
        close(pipefd[1]);
    } else { // Child process
        close(pipefd[1]); // Close the writing end in the child
        read(pipefd[0], buffer, BUFFER_SIZE);
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);
    }
}

void child_writes_parent_reads() {
    int pipefd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];
    
    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        close(pipefd[1]); // Close the writing end in the parent
        read(pipefd[0], buffer, BUFFER_SIZE);
        printf("Parent received: %s\n", buffer);
        close(pipefd[0]);
    } else { // Child process
        close(pipefd[0]); // Close the reading end in the child
        const char *data = "Hello parent!";
        write(pipefd[1], data, strlen(data));
        printf("Child wrote: %s\n", data);
        close(pipefd[1]);
    }
}

int main() {
    printf("Parent writing, child reading:\n");
    parent_writes_child_reads();
    printf("\nChild writing, parent reading:\n");
    child_writes_parent_reads();
    return 0;
}