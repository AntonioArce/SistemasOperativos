#include <stdio.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define TAM 8192
mqd_t mqdes;
char mensaje[TAM];

int main()
{
	unsigned int respuesta;
	pid_t pid1=fork();
	mqdes= mq_open("/MiColaDeMensj",O_RDWR | O_CREAT, 0664,NULL);

	if(pid1==-1)
		perror("\n Error al crear proceso");
	if(pid1==0)
	{
		printf("\n Soy el proceso %d \n",getpid());
		printf("\n Que desea hacer: ");
		printf("\n 1. Mandar un mensaje \n");
		printf("\n 2. Leer un mensaje \n");
		scanf("%d",&respuesta);
		if(respuesta==1)
		{
			printf("\n Escribe un mensaje \n");
			scanf("%s",mensaje);
			mq_send(mqdes,mensaje,strlen(mensaje)+1,0);
			printf("\n Mensaje enviado\n");
		}
		else if(respuesta==2)
		{
			mq_receive(mqdes,mensaje,TAM,NULL);
			printf("\n El mensaje recibido es: %s \n",mensaje);
		}
		mq_close(mqdes);	
		exit(0);
	}
	else
	{
		wait(NULL);
	}
	return 0;
}
