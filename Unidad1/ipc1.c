#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void main() {
    int fd[2];
    
    pipe(fd);
    time_t hora;
    char *fecha ;
    time(&hora);
    fecha = ctime(&hora) ;
    pid_t pid = fork();

    if (pid == 0) {
        // HIJO: solo lee
        close(fd[1]);
        printf("Soy el proceso hijo con PID: %d\n", getpid());
        read(fd[0], &fecha, sizeof(fecha));
        printf("Fecha/hora: %s", fecha);
        close(fd[0]);
    }
    else {
        // PADRE: solo escribe
        close(fd[0]);
        write(fd[1], &fecha, sizeof(fecha));
        close(fd[1]);
        wait(NULL);
    }
}