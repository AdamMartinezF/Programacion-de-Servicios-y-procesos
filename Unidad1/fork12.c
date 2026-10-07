#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid2, pid3, pid_hijo1, pid_hijo2, pid_hijo3;
    pid = fork();
    if(pid==0){
        pid2 = fork();
        if(pid2 == 0){
            pid3 = fork();
            if(pid3 == 0){
                printf("Mi PID es: %d\n", getpid());
                printf("El PID de mi padre: %d\n", getppid());
                printf("La suma de nuestros PIDS es: %d\n", (getpid() + getppid()));

            }else{
                pid_hijo3 = wait(NULL);
                printf("Mi PID es: %d\n", getpid());
                printf("El PID de mi padre: %d\n", getppid());
                printf("La suma de nuestros PIDS es: %d\n", (getpid() + getppid()));
            }
        }else{
            pid_hijo2 = wait(NULL);
            printf("Mi PID es: %d\n", getpid());
            printf("El PID de mi padre: %d\n", getppid());
            printf("La suma de nuestros PIDS es: %d\n", (getpid() + getppid()));
        }
    }else{
        pid_hijo1 = wait(NULL);
        printf("Mi PID es: %d\n", getpid());
        printf("El PID de mi padre: %d\n", getppid());
        printf("La suma de nuestros PIDS es: %d\n", (getpid() + getppid()));
    }
    exit(0);
}