#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    if (pid == 0) {
        // HIJO: lee y suma
        close(fd[1]);
        char buffer[32];
        int suma = 0;
        while (1) {
            read(fd[0], buffer, sizeof(buffer));
            if (strcmp(buffer, "+") == 0) {
                printf("Recibido carácter +\n");
                break;
            }
            int num = atoi(buffer);
            printf("Numero a sumar: %d\n", num);
            suma += num;
        }
        printf("La suma total es igual a: %d\n", suma);
        close(fd[0]);
    } else {
        // PADRE: pide por teclado y escribe
        close(fd[0]);
        char entrada[32];
        do {
            scanf("%s", entrada);
            write(fd[1], entrada, sizeof(entrada));
        } while (strcmp(entrada, "+") != 0);
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}