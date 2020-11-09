#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

void *Primo(void *argumentos)
{
    printf("\n\t Hola soy un hilo creado dentro del hilo principal\n");
    printf("\n\t El numero es primo \n");
    pthread_exit(NULL);
}

void *Compuesto(void *argumentos)
{
    int **num=(int**)argumentos;
    printf("\n\t Hola soy un hilo creado dentro del hilo principal\n");
    printf("\n\t Sus factores primos son \n");
    printf("\t");
    for(int i=2;**num > 1;i++)
    {
        while(**num%i==0)
        {
            printf(" %d ",i);
            **num /= i;
        }
    }
    
    
    printf("\n");
    pthread_exit(NULL);
}

void *HiloP(void *argumentos)
{
    pthread_t primo,compuesto;
    int *num = (int*)argumentos;
    int cont = 0;
    printf("\n Hola soy el hilo principal\n");
    sleep(0);

    for(int i = 1;i <= *num;i++)
    {
        if(*num%i==0)
            cont++;
    }
    
    if(cont>2) //Descompone el numero en sus factores primos
    {
        pthread_create(&compuesto,NULL,Compuesto,&num);
        pthread_join(compuesto,NULL);
    }
    else//Imprime que es primo
    {
        pthread_create(&primo,NULL,Primo,NULL);
        pthread_join(primo,NULL);
    }
    pthread_exit(NULL);
}

int main()
{
    int numero;
    pthread_t hilo;
    printf("\n Inserte un numero entero: ");
    scanf("%d",&numero);
    printf("\n Creacion del Hilo\n");
    pthread_create(&hilo,NULL,HiloP,&numero);

    pthread_join(hilo,NULL);
    printf("\n Hilo finalizado!!!\n ");

    return 0;
}