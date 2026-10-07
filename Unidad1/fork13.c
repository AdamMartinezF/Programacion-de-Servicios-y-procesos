#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t abuelo;

    printf("Mi PID es: %d\n", getpid());
    printf("El PID de mi padre: %d\n", getppid());

    pid_t pid2 = fork();
    if (pid2 == 0) {
        
        printf("Mi PID es: %d\n", getpid());
        printf("El PID de mi padre: %d\n", getppid());
        abuelo = getppid();          

        pid_t pid3 = fork();
        if (pid3 == 0) {
            // P3 (hijo de P2, abuelo P1)
            printf("Mi PID es: %d\n", getpid());
            printf("El PID de mi padre: %d\n", getppid());
            printf("El PID de mi abuelo: %d\n", abuelo);
            abuelo = getppid();      

            pid_t pid5 = fork();
            if (pid5 == 0) {
                printf("Mi PID es: %d\n", getpid());
                printf("El PID de mi padre: %d\n", getppid());
                printf("El PID de mi abuelo: %d\n", abuelo);
                
            }
            wait(NULL);              
            
        }

        pid_t pid4 = fork();         
        if (pid4 == 0) {
           
            printf("Mi PID es: %d\n", getpid());
            printf("El PID de mi padre: %d\n", getppid());
            printf("El PID de mi abuelo: %d\n", abuelo);
            abuelo = getppid();      // P2: será el abuelo de P6

            pid_t pid6 = fork();
            if (pid6 == 0) {
                printf("Mi PID es: %d\n", getpid());
                printf("El PID de mi padre: %d\n", getppid());
                printf("El PID de mi abuelo: %d\n", abuelo);
                
            }
            wait(NULL);             
            
        }

        wait(NULL);                  
        wait(NULL);                  
        
    }

    wait(NULL);                      
    
}