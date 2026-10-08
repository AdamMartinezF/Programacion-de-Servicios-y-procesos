#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if (pid == 0) {
        // HIJO: solo lee
        close(fd[1]);
        printf("Soy el proceso hijo con PID: %d\n", getpid());

        int contador = 0;
        int numero;
        char suma;

        read(fd[0], &numero, sizeof(numero));
        printf("Numero a sumar: %d\n", numero);
        contador += numero;

        read(fd[0], &numero, sizeof(numero));
        printf("Numero a sumar: %d\n", numero);
        contador += numero;

        read(fd[0], &numero, sizeof(numero));
        printf("Numero a sumar: %d\n", numero);
        contador += numero;

        read(fd[0], &suma, sizeof(suma));
        if (suma == '+') {
            printf("Recibido caracter %c\n", suma);
            printf("La suma total es igual a: %d\n", contador);
        }

        close(fd[0]);
    } else {
        // PADRE: solo escribe
        close(fd[0]);

        int numero1, numero2, numero3;
        numero1 = 40;
        numero2 = 54;
        numero3 = 10;
        char mas = '+';

        write(fd[1], &numero1, sizeof(numero1));
        write(fd[1], &numero2, sizeof(numero2));
        write(fd[1], &numero3, sizeof(numero3));
        write(fd[1], &mas, sizeof(mas));

        close(fd[1]);
        wait(NULL);
    }

    return 0;
}