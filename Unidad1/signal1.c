/* El programa muestra cómo capturar una señal del sistema (en este caso SIGINT) 
   y cómo asignarle un manejador personalizado -> función que se ejecuta cuando llega la señal*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include <time.h>



void fun_signal(int signum){
  signal(SIGINT,SIG_DFL);   // Se "re-arma" la señal con su acción por defecto
}

int main(){
  signal(SIGINT,fun_signal); // Esta línea registra la función manejadora para la señal SIGINT. A partir de aquí, si se pulsa Ctrl+C, se ejecutará fun_signal()
  time_t hora; 
  int pid = getpid();
  char *fecha ;
  time(&hora);
  fecha = ctime(&hora);
  printf("Inicio del proceso %d: %s\n", pid, fecha);
  pause();
  time(&hora);
  fecha = ctime(&hora);
  printf("Fin del proceso %d: %s\n", pid, fecha);
  return 0;
}