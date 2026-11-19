#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int fd[2]; 

void par(int sig) { 
    int n;
    read(fd[0], &n, sizeof(n)); 
    printf("Número par %d recibido por el proceso P2 con pid %d\n", n, getpid());
    signal(SIGUSR1, par);
}

void impar(int sig) { 
    int n;
    read(fd[0], &n, sizeof(n));
    printf("Número impar %d recibido por el proceso P3 con pid %d\n", n, getpid());
    signal(SIGUSR2, impar); 
}

int main() {
    int n, p2, p3;

    pipe(fd);

    p2 = fork();
    if (p2 == 0) {
        // código de P2
        signal(SIGUSR1, par);
        while (1)
            pause();
    } else {
        p3 = fork(); 
        if (p3 == 0) {
            
            signal(SIGUSR2, impar); 
            while (1)
                pause(); 
        } else {
            printf("Introduce número:\n");
            scanf("%d", &n); 
            while (n != 0) {
                write(fd[1], &n, sizeof(n)); 
                if (n % 2 == 0) {
                    kill(p2, SIGUSR1); 
                } else {
                    kill(p3, SIGUSR2); 
                }
                sleep(1);
                printf("Introduce número:\n");
                scanf("%d", &n); 
            }
            printf("Mandando señal de terminación al proceso hijo P2 con pid %d\n", p2);
            kill(p2, SIGTERM); 
            printf("Mandando señal de terminación al proceso hijo P3 con pid %d\n", p3);
            kill(p3, SIGTERM); 
            printf("Fin proceso padre con pid %d\n", getpid());
        }
    }

    return 0;
}