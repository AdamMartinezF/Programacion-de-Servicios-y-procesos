#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int acumulado = getpid();
    pid_t pid2 = fork();
    if (pid2 == 0) {
        if (getpid() % 2 == 0)
            acumulado = acumulado + 10;
        else
            acumulado = acumulado - 100;
        printf("%d\n", acumulado);
        pid_t pid5 = fork();
        if (pid5 == 0) {
            
            if (getpid() % 2 == 0)
                acumulado = acumulado + 10;
            else
                acumulado = acumulado - 100;
            printf("%d\n", acumulado);
        }
        wait(NULL);
    }
    pid_t pid3 = fork();
    if (pid3 == 0) {
        
        if (getpid() % 2 == 0)
            acumulado = acumulado + 10;
        else
            acumulado = acumulado - 100;
        printf("%d\n", acumulado);
        pid_t pid4 = fork();
        if (pid4 == 0) {
            
            if (getpid() % 2 == 0)
                acumulado = acumulado + 10;
            else
                acumulado = acumulado - 100;
            printf("%d\n", acumulado);
        }
        wait(NULL);
    }
    wait(NULL);
    wait(NULL);
    exit(0);
}