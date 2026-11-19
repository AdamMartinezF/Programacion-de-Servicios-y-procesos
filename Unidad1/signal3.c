#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void fun_signal(int signum) {
    FILE *f = fopen("salidas.txt", "a"); 
    time_t t = time(NULL); 
    char hora[10];

    strftime(hora, 10, "%H:%M:%S", localtime(&t)); 
    fprintf(f, "Señal SIGINT recibida a las %s\n", hora);
    fclose(f); // cerrar

    signal(SIGINT, fun_signal); 
}

int main() {
    signal(SIGINT, fun_signal); 
    while (1)
        pause(); 
    return 0;
}