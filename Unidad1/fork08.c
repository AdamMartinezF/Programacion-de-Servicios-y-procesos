#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2;
    printf("AAA \n");
    pid1 = fork();
    if (pid1 == 0) {
        printf("BBB \n");
    } else {
        pid2 = fork();
        if (pid2 == 0) {
            printf("CCC \n");
        } else {
            wait(NULL); 
            wait(NULL); 
            printf("CCC \n"); 
        }
    }
    exit(0);
}
//B: El programa siempre empieza saliendo con AAA y luego ya continua haciendo BBB/CCC y ademas CCC se repite dos veces en el programa ya que justo antes de llegar a el hay otro fork que genera otro proceso extra.
//C: El codigo