#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
//tengo que hacer que un proceso padre tenga un hijo y ese hijo otro hijo y que cada uno enseñe su PID y el de su papa, los procesos padres deben terminar
int main() {
    pid_t pid, pid2, pid_hijo1, pid_hijo2;
    pid = fork();
    if(pid == 0){
        pid2 = fork();
        if(pid2 == 0){
            printf("Soy el proceso P3.");
            printf("Mi PID es: %d\n", getpid());
            printf("El PID de mi padre: %d\n", getppid()); 
        }else{
            pid_hijo2 = wait(NULL);
            printf("Soy el proceso P2.");
            printf("Mi PID es: %d\n", getpid());
            printf("El PID de mi padre: %d\n", getppid()); 
        }
    }else{
        pid_hijo1 = wait(NULL);
        printf("Soy el proceso P1.");
        printf("Mi PID es: %d\n", getpid());
        printf("El PID de mi padre: %d\n", getppid()); 
    }
    exit(0);
}