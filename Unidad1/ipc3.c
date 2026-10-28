#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if (pid == 0) {
        // Hijo escribe
        close(fd[0]);
        int numero1, numero2;
        srand(time(NULL));
        numero1 = rand() % 50;
        numero2 = rand() % 50;
        write(fd[1], &numero1, sizeof(numero1));
        write(fd[1], &numero2, sizeof(numero2));
        close(fd[1]);
    } else {
        // Padre lee
        close(fd[1]);
        int numero, numero2;
        read(fd[0], &numero, sizeof(numero));
        read(fd[0], &numero2, sizeof(numero2));
        printf("%d + %d = %d\n", numero, numero2, numero + numero2);
        printf("%d - %d = %d\n", numero, numero2, numero - numero2);
        printf("%d * %d = %d\n", numero, numero2, numero * numero2);
        printf("%d / %d = %d\n", numero, numero2, numero / numero2);
        wait(NULL);
    }

    return 0;
}