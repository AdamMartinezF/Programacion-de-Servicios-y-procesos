#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, pid2, pid_hijo1, pid_hijo2;

    pid = fork();
    if (pid == 0) {
        int suma = 0;
        for (int i = 1; i <= 100; i++) {
            suma += i;
        }
        printf("Soy el proceso hijo 1:\n");
        printf("Mi PID es: %d\n", getpid());
        printf("Operacion realizada: Suma 1..100\n");
        printf("Resultado: %d\n", suma);
    } else if (pid > 0) {
        pid2 = fork();
        if (pid2 == 0) {
            int suma = 0;
            for (int i = 101; i <= 200; i++) {
                suma += i;
            }
            printf("Soy el proceso hijo 2:\n");
            printf("Mi PID es: %d\n", getpid());
            printf("Operacion realizada: Suma 101..200\n");
            printf("Resultado: %d\n", suma);
        } else if (pid2 > 0) {
            pid_hijo1 = wait(NULL);
            pid_hijo2 = wait(NULL);
            printf("Soy el padre.\n");
            printf("Mi PID es: %d\n", getpid());
            printf("Todos los calculos han finalizado.\n");
        }
    }

    exit(0);
}