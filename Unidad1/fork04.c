#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid2, pid_hijo1, pid_hijo2;
    pid = fork();
    if (pid == 0){    
        printf("Soy el proceso hijo 1:\n");   
        printf("Mi PID es: %d\n", getpid());
        printf("El PID de mi padre: %d\n", getppid()); 
        sleep(3);  
        exit(0);
    } 
    pid2 = fork();
    if(pid2==0){
        printf("Soy el proceso hijo 2:\n");   
        printf("Mi PID es: %d\n", getpid());
        printf("El PID de mi padre: %d\n", getppid()); 
        sleep(1);
        exit(0);
    }
    else { // Proceso padre 
        pid_hijo1 = wait(NULL);
        pid_hijo2 = wait(NULL);
        printf("Soy el padre: \n");
        printf("Mi PID es: %d\n", getpid());
        printf("El PID de mi padre: %d\n", getppid()); 
        printf("Todos mis hijos ya han terminado.");
    }
    exit(0);
}