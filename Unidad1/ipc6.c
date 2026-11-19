#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd1[2], fd2[2], fd3[2], fd4[2];

    pipe(fd1);
    pipe(fd2);
    pipe(fd3); 
    pipe(fd4);
    pid_t pid1 = fork();
    if (pid1 == 0) {
        close(fd1[1]); 
        close(fd2[0]); close(fd2[1]); 
        close(fd3[0]); 
        close(fd4[0]); close(fd4[1]); 

        int n1, n2, suma;
        read(fd1[0], &n1, sizeof(n1));
        read(fd1[0], &n2, sizeof(n2));
        close(fd1[0]);

        suma = n1 + n2;

        write(fd3[1], &suma, sizeof(suma));
        close(fd3[1]);

        exit(0);
    } else {
        pid_t pid2 = fork();
        if (pid2 == 0) {
            close(fd1[0]); close(fd1[1]); 
            close(fd2[1]); 
            close(fd3[0]); close(fd3[1]); 
            close(fd4[0]); 
            int n1, n2, producto;
            read(fd2[0], &n1, sizeof(n1));
            read(fd2[0], &n2, sizeof(n2));
            close(fd2[0]);
            producto = n1 * n2;
            write(fd4[1], &producto, sizeof(producto));
            close(fd4[1]);
            exit(0);
        } else {
            close(fd1[0]); 
            close(fd2[0]); 
            close(fd3[1]); 
            close(fd4[1]); 
            int numero1, numero2;
            int suma, producto;
            printf("Introduce el primer numero entero: ");
            scanf("%d", &numero1);
            printf("Introduce el segundo numero entero: ");
            scanf("%d", &numero2);
            write(fd1[1], &numero1, sizeof(numero1));
            write(fd1[1], &numero2, sizeof(numero2));
            close(fd1[1]);
            write(fd2[1], &numero1, sizeof(numero1));
            write(fd2[1], &numero2, sizeof(numero2));
            close(fd2[1]);
            read(fd3[0], &suma, sizeof(suma));
            close(fd3[0]);
            read(fd4[0], &producto, sizeof(producto));
            close(fd4[0]);
            wait(NULL);
            wait(NULL);
            printf("La suma es: %d \n", suma);
            printf("E producto es: %d\n", producto);
        }
    }
    return 0;
}