#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int segundos = 0; // contador

void Funsignal(int sig) {
    segundos += 5; // sumar 5
    printf("Han transcurrido %d segundos\n", segundos);
    signal(SIGALRM, Funsignal); // rearmar gestor
    alarm(5); // nueva alarma
}

int main() {
    signal(SIGALRM, Funsignal); // registrar gestor
    alarm(5); // primera alarma

    while (1)
        pause(); // esperar señal

    return 0;
}