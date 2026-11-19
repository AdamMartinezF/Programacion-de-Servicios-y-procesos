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
        int alumnoTemp;
        int contador = 0;
        for (int i = 0; i < 10; i++) { 
            read(fd1[0], &alumnoTemp, sizeof(alumnoTemp));
            if (alumnoTemp >= 5) { 
                contador = contador + 1;                    
            }
        }

        close(fd1[0]);
        write(fd3[1], &contador, sizeof(contador)); 
        close(fd3[1]);
        exit(0);
    } else {
        pid_t pid2 = fork();
        if (pid2 == 0) {
            close(fd1[0]); close(fd1[1]); 
            close(fd2[1]); 
            close(fd3[0]); close(fd3[1]); 
            close(fd4[0]); 

            int notaTemp;
            int media = 0; 
            int maxima = 0;

            for (int i = 0; i < 10; i++) { 
                read(fd2[0], &notaTemp, sizeof(notaTemp));
                if (notaTemp > maxima) {
                    maxima = notaTemp;
                }
                media = media + notaTemp;
            }
            media = (media / 10);
            close(fd2[0]);
            write(fd4[1], &media, sizeof(media));   
            write(fd4[1], &maxima, sizeof(maxima)); 
            close(fd4[1]);
            exit(0);
        } else {
            close(fd1[0]); 
            close(fd2[0]); 
            close(fd3[1]); 
            close(fd4[1]); 
            int numeroTemp;
            int media, maxima, alumnosAprobados;

            printf("Introduce las notas de 10 alumnos:\n");
            for (int i = 0; i < 10; i++) {
                printf("Introduce una nota: ");
                scanf("%d", &numeroTemp); 
                write(fd1[1], &numeroTemp, sizeof(numeroTemp)); 
                write(fd2[1], &numeroTemp, sizeof(numeroTemp)); 
            }
            close(fd1[1]);
            close(fd2[1]);
            read(fd3[0], &alumnosAprobados, sizeof(alumnosAprobados));
            close(fd3[0]);
            read(fd4[0], &media, sizeof(media));
            read(fd4[0], &maxima, sizeof(maxima));
            close(fd4[0]);
            wait(NULL);
            wait(NULL);
            printf("La maxima es: %d \n", maxima);
            printf("La media es: %d \n", media);
            printf("La cantidad de aprobados es: %d\n", alumnosAprobados);
        }
    }
    return 0;
}