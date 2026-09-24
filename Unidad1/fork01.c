#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid_hijo;
    pid = fork();

    if (pid == -1) {
        printf("ERROR !!! No se ha podido crear el proceso hijo...\n");
        exit(-1);       
    }

    if (pid == 0)    
        printf("Soy el proceso hijo:\n");   
        printf("Mi PID es: %d\n", getpid());
        printf("El PID de mi padre: %d\n", getppid());   
    } 
    else { // Proceso padre 
        pid_hijo = wait(NULL);
        printf("Soy el proceso padre:\n");
        printf("Mi PID: %d\n", getpid());
        printf("El PID de mi padre: %d\n", getppid());
        printf("Mi hijo tenía el PID: %d\n", pid);
    }

    exit(0);
}