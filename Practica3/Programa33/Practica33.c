#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
#include<sys/types.h>

int main()
{
	pid_t pid;
	system("touch Archivo.txt");
	for(int i=0;i<5;i++)
	{
		pid=fork();
		if(pid==-1)
		{
			perror("\n Error al crear el Proceso\n");
		}
		if(pid==0)
		{
			printf("\n Soy el proceso %d: %d",i+1,getpid());
			if(i==0)
			{
				system("echo 'Hola' >> Archivo.txt");
				printf("\n Escribiendo palabra\n");
			}
			else if(i==1)
			{
				system("echo 'esta' >> Archivo.txt");
				printf("\n Escribiendo palabra\n");
			}
			else if(i==2)
			{
				system("echo 'es' >> Archivo.txt");
				printf("\n Escribiendo palabra\n");
			}
			else if(i==3)
			{
				system("echo 'mi' >> Archivo.txt");
				printf("\n Escribiendo palabra\n");
			}
			else if(i==4)
			{
				system("echo 'practica' >> Archivo.txt");
				printf("\n Escribiendo palabra\n");
			}
			sleep(2);
			exit(0);
		}
		wait(NULL);
	}
	printf("\n Soy el proceso padre: %d\n",getpid());
	system("echo 'UNO' >> Archivo.txt");
	printf("\n Escribiendo palabra\n");
	printf("\n");
	system("cat Archivo.txt");
	return 0;
}
