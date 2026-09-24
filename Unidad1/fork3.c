#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("Inicio\n");
    pid_t pid = fork();
    printf("Después del fork\n");
    if (pid == 0) {
        printf("Soy el hijo\n");
    } else {
        printf("Soy el padre\n");
    }
printf("Fin\n");
}
//Pregunta A
//Existen 2 procesos a partir de la linea 9, que es en la que s ehace el fork, hasta entonces solo habia un proceso
//Pregunta B
//El padre ejecuta: Las impresiones de Inicio, Despues del fork, Soy el Padre y fin
//EL hijo ejecuta: Las impresiones de Despues del fork, soy el hijo y fin.
//Pregunta C:
//Inicio 1 vez, Despues del fork 2, soy el hijo 1, soy el padre 1, fin 2, Y los mensajes que pueden aparecer en distinto orden son 
// el de Despues del fork el de soy el hijo, el de soy el padre y fin, que dependen de que proceso se ejecuta antes.