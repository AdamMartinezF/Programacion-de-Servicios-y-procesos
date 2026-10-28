#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);
    pid_t pid = fork();
    if (pid == 0) {
        // HIJO (P2): lee de fd1, calcula factorial y escribe en fd2
        close(fd1[1]);
        close(fd2[0]);
        int num;
        read(fd1[0], &num, sizeof(num));
        close(fd1[0]);
        int fact = 1;
        for (int i = 1; i <= num; i++) {
            fact *= i;
        }
        write(fd2[1], &fact, sizeof(fact));
        close(fd2[1]);
    } else {
        // PADRE (P1): genera numero, escribe en fd1 y lee de fd2
        close(fd1[0]);
        close(fd2[1]);
        srand(time(NULL));
        int num = rand() % 11;
        printf("El proceso padre genera el numero %d en el pipe1\n", num);
        write(fd1[1], &num, sizeof(num));
        close(fd1[1]);
        int resultado;
        read(fd2[0], &resultado, sizeof(resultado));
        close(fd2[0]);
        printf("El factorial calculado por el proceso hijo: %d! = %d\n", num, resultado);
        wait(NULL);
    }
    return 0;
}