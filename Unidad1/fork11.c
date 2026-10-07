#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    pid_t pid, pid2, pid3, pid_hijo1, pid_hijo2,pid_hijo3;
    pid = fork();
    if (pid == 0){
        if(getpid() % 2 == 0){
                printf("Mi PID es: %d\n", getpid());
                printf("El PID de mi padre: %d\n", getppid());
            }else{
                printf("Mi PID es: %d\n", getpid());
            }
    }else{
        pid2 = fork();
        if(pid2 == 0){
            pid3 = fork();
            if(pid3 == 0){
                if(getpid() % 2 == 0){
                    printf("Mi PID es: %d\n", getpid());
                    printf("El PID de mi padre: %d\n", getppid());
                }else{
                    printf("Mi PID es: %d\n", getpid());
                }
            }else{
                pid_hijo3 = wait(NULL);
                if(getpid() % 2 == 0){
                    printf("Mi PID es: %d\n", getpid());
                    printf("El PID de mi padre: %d\n", getppid());
                }else{
                    printf("Mi PID es: %d\n", getpid());
                }   
            }
        }else{
            pid_hijo1 = wait(NULL);
            pid_hijo2 = wait(NULL);
            if(getpid() % 2 == 0){
                printf("Mi PID es: %d\n", getpid());
                printf("El PID de mi padre: %d\n", getppid());
            }else{
                printf("Mi PID es: %d\n", getpid());
            }
        }
    }
    exit(0);
}
//El orden no esta determinado, lo unico que se sabe es que p1 se ejecutara despues de P2 y P3 y que P3 lo hara despues de P4