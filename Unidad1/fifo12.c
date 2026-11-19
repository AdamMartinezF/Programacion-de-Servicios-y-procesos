#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd1, fd2, n, i, fact = 1;

    fd1 = open("/tmp/FIFO1", O_RDONLY); 
    fd2 = open("/tmp/FIFO2", O_WRONLY);

    read(fd1, &n, sizeof(n)); 

    for (i = 2; i <= n; i++){
        fact *= i;
    } 
        
    write(fd2, &fact, sizeof(fact)); 
    return 0;
}