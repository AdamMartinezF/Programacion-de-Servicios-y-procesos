#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid_hijo;
    pid = fork();
    if (pid == 0) {     
        printf("Adam Martinez Fikri\n");
    } 
    else {
        pid_hijo = wait(NULL);
        printf("Soy el proceso padre:\n");
        printf("Mi PID: %d\n", getpid());
        printf("Mi hijo tenía el PID: %d\n", pid);
    }
    exit(0);
}