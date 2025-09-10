
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler(int codigo_senal);

int main () {
    printf("<%ld>/<%ld>", (long)getpid(), (long)getppid());
    signal(SIGUSR1, &handler);

    while(1) {
        printf("A mimir por un segundo...\n");
        sleep(1); 
    }
    return 0;
}

void handler(int codigo_senal)
{
    printf("Recibimos un %d, USR\n", codigo_senal);
    //exit(1);
}
