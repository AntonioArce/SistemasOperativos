#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *Hilo1(void *argumentos)
{
    printf("\n Hola soy el hijo hilo 1 c:\n");
    sleep(1);
    pthread_exit(NULL);
}
void *Hilo2(void *argumentos)
{
    printf("\n Hola soy el hijo hilo 2 c:\n");
    sleep(1);
    pthread_exit(NULL);
}
void *HiloP(void *argumentos)
{
    pthread_t hilo1,hilo2;
    printf("\n Hola soy el Hilo principal. :)\n");
    sleep(2);
    pthread_create(&hilo1,NULL,Hilo1,NULL);
    pthread_create(&hilo2,NULL,Hilo2,NULL);
    pthread_join(hilo1,NULL);
    pthread_join(hilo2,NULL);

    pthread_exit(NULL);
}

int main()
{
    pthread_t hiloP;
    printf("\n Creando hilo principal: \n");
    pthread_create(&hiloP,NULL,HiloP,NULL);
    sleep(3);
    pthread_join(hiloP,NULL);
    printf("\n Hilo Finalizado \n");
}