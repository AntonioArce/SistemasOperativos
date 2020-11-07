#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CICLO 10000
static void *hilo1funcion(void *arg);
static void *hilo2funcion(void *arg);
int variable=0;

sem_t sem1; //Declaracion de nuestro semaforo

int main(int argc,char *argv[])
{
	int tiempo=atoi(argv[1]);
	pthread_t hilo1,hilo2;
	sem_init(&sem1,0,1);
	pthread_create(&hilo1,NULL,*hilo1funcion,NULL);
	pthread_create(&hilo2,NULL,*hilo2funcion,NULL);

	pthread_join(hilo1,NULL);
	pthread_join(hilo2,NULL);
	sleep(tiempo);
	printf("\n El valor de nuestra variable es: %d \n",variable);
	return 0;
}
static void *hilo1funcion(void *arg)
{
	printf("\n Primer hilo ejecutandose /...............\n");
	sem_wait(&sem1);
	for(int i = 0;i< CICLO; i++)
	{
		variable++;
	}
	sem_post(&sem1);
	sleep(1);
}
static void *hilo2funcion(void *arg)
{
	printf("\n Segundo Hilo ejecutandose /..............\n");
	sem_wait(&sem1);
	for(int i = 0;i< CICLO; i++)
	{
		variable--;
	}
	sem_post(&sem1);
	sleep(1);
}
