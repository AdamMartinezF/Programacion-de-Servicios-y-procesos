#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main(){
    pid_t pid_hijo1;
    {
    printf("CCC \n");
        if (fork()!=0)
        {
            pid_hijo1 = wait(NULL);
            printf("AAA \n");
        } else {
            printf("BBB \n");
        }
    exit(0);
    }
}
//IMPORTANTE AÑADIR LA LIBRERIA DE <sys/wait.h>!!!
//B: La salida es siempre CCC y luego BBB o AAA, no esta determinado, ya que depende de lo que haga el procesador
//C: Si añades una linea antes de AAA para que espere a su hijo siempre sera CCC BBB AAA.Wñ