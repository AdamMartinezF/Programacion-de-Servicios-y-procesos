#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

int veces = 0, segundos = 0, contador = 0; 

void fun_signal(int signum) {
    time_t t = time(NULL); 
    char hora[10];

    strftime(hora, 10, "%H:%M:%S", localtime(&t)); // formato hora
    printf("Señal de alarma recibida a las %s\n", hora);
    contador++; // contar

    signal(SIGALRM, fun_signal); 
    if (contador < veces)
        alarm(segundos); 
}

int main() {
    printf("Cuántas veces sonará la alarma?:\n");
    scanf("%d", &veces); 
    printf("Cuantos segundos durará la alarma?:\n");
    scanf("%d", &segundos); 

    signal(SIGALRM, fun_signal); 
    printf("Alarma activada\n");
    alarm(segundos); 

    while (contador < veces)
        pause(); 

    printf("Alarma desactivada\n");
    return 0;
}