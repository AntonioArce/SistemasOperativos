#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <semaphore.h>

sem_t sem1;

void *SubHilo1(void *argumentos)
{
    printf("\n\t\t Soy el hilo %ld\n",pthread_self());
    sleep(1);
    pthread_exit(NULL);
}
void *SubHilo2(void *argumentos)
{
    printf("\n\t\t Soy el hilo %ld\n",pthread_self());
    sleep(1);
    pthread_exit(NULL);
}
void *Hilo1(void *argumentos)
{
    pthread_t subhilo1,subhilo2;
    sem_wait(&sem1);
    printf("\n Soy el hilo %ld creado por el proceso %d",pthread_self(),getpid());
    sleep(1);
    printf("\n Ahora creare 2 hilos mas\n ");
    pthread_create(&subhilo1,NULL,SubHilo1,NULL);
    pthread_create(&subhilo2,NULL,SubHilo2,NULL);

    pthread_join(subhilo1,NULL);
    pthread_join(subhilo2,NULL);

    sem_post(&sem1);
    pthread_exit(NULL);
}
void *Hilo2(void *argumentos)
{
    pthread_t subhilo1,subhilo2;

    sem_wait(&sem1);
    printf("\n Soy el hilo %ld creado por el proceso %d",pthread_self(),getpid());
    sleep(1);
    printf("\n Ahora creare 2 hilos mas\n ");
    pthread_create(&subhilo1,NULL,SubHilo1,NULL);
    pthread_create(&subhilo2,NULL,SubHilo2,NULL);

    pthread_join(subhilo1,NULL);
    pthread_join(subhilo2,NULL);

    sem_post(&sem1);
    pthread_exit(NULL);
}
void *Hilo3(void *argumentos)
{
    pthread_t subhilo1,subhilo2;

    sem_wait(&sem1);
    printf("\n Soy el hilo %ld creado por el proceso %d",pthread_self(),getpid());
    sleep(1);
    printf("\n Ahora creare 2 hilos mas\n ");
    pthread_create(&subhilo1,NULL,SubHilo1,NULL);
    pthread_create(&subhilo2,NULL,SubHilo2,NULL);

    pthread_join(subhilo1,NULL);
    pthread_join(subhilo2,NULL);

    sem_post(&sem1);
    pthread_exit(NULL);
}

int main()
{
    pid_t pid;
    pthread_t hilo1,hilo2,hilo3;
    sem_init(&sem1,0,1);
    pid=fork();
    if(pid==-1)
    {
        perror("\n Error al crear proceso\n");
        exit(-1);
    }
    if(pid==0)
    {
        printf("\n Soy el proceso hijo %d y mi padre es: %d \n",getpid(),getppid());
        printf("\n Ahora creare 3 hilos\n");
        sleep(1);
        pthread_create(&hilo1,NULL,Hilo1,NULL);
        pthread_create(&hilo2,NULL,Hilo2,NULL);
        pthread_create(&hilo3,NULL,Hilo2,NULL);
        sleep(2);

        pthread_join(hilo1,NULL);
        pthread_join(hilo2,NULL);
        pthread_join(hilo3,NULL);
        exit(0);
    }
    else
    {
        wait(NULL);
        printf("\n Soy el proceso padre %d\n", getpid());
    }
}