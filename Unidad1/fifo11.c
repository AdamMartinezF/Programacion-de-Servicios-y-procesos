#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    int fd1, fd2, n, fact;

    mkfifo("/tmp/FIFO1", 0666); 
    mkfifo("/tmp/FIFO2", 0666);

    fd1 = open("/tmp/FIFO1", O_WRONLY); 
    fd2 = open("/tmp/FIFO2", O_RDONLY);

    srand(time(NULL)); 
    n = rand() % 11;
    write(fd1, &n, sizeof(n));

    read(fd2, &fact, sizeof(fact));
    printf("%d! = %d\n", n, fact);

    unlink("/tmp/FIFO1"); 
    unlink("/tmp/FIFO2");
    return 0;
}