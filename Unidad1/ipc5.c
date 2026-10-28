#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);
    pid_t pid = fork();
    if (pid == 0) {
        // HIJO (P2): pide DNI, escribe en fd1 y lee letra de fd2
        close(fd1[0]);
        close(fd2[1]);
        int dni;
        printf("Pon tu DNI:");
        scanf("%d", &dni);
        write(fd1[1], &dni, sizeof(dni));
        close(fd1[1]);
        char letra;
        read(fd2[0], &letra, sizeof(letra));
        close(fd2[0]);
        printf("la letra del DNI es %c\n", letra);
    } else {
        // PADRE (P1): lee DNI de fd1, calcula letra y escribe en fd2
        close(fd1[1]);
        close(fd2[0]);
        int dni;
        read(fd1[0], &dni, sizeof(dni));
        close(fd1[0]);
        char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
        char letra = letras[dni % 23];
        write(fd2[1], &letra, sizeof(letra));
        close(fd2[1]);
        wait(NULL);
    }
    return 0;
}