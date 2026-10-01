#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid2, pid3, pid_hijo1, pid_hijo2, pid_hijo3;

    pid = fork();
    if (pid == 0) {
        printf("Soy el proceso hijo 1:\n");
        printf("Mi PID es: %d\n", getpid());
        printf("El PID de mi padre: %d\n", getppid());
        sleep(5);
        printf("Hijo 1 terminado.\n");
    } else if (pid > 0) {
        pid2 = fork();
        if (pid2 == 0) {
            printf("Soy el proceso hijo 2:\n");
            printf("Mi PID es: %d\n", getpid());
            printf("El PID de mi padre: %d\n", getppid());
            sleep(2);
            printf("Hijo 2 terminado.\n");
        } else if (pid2 > 0) {
            pid3 = fork();
            if (pid3 == 0) {
                printf("Soy el proceso hijo 3:\n");
                printf("Mi PID es: %d\n", getpid());
                printf("El PID de mi padre: %d\n", getppid());
                sleep(4);
                printf("Hijo 3 terminado.\n");
            } else if (pid3 > 0) {
                pid_hijo1 = wait(NULL);
                pid_hijo2 = wait(NULL);
                pid_hijo3 = wait(NULL);
                printf("Soy el padre.\n");
                printf("Mi PID es: %d\n", getpid());
                printf("Mis tres Hijos han terminado.\n");
            }
        }
    }

    exit(0);
}
//A, si que podemos asegurarnos, primero es P3 luego P4 y luego P2
//B Si eliminamos el sleep el orden pasa a ser indeterminado.