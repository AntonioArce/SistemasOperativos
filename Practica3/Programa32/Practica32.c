#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
#include<sys/types.h>

int main()
{
	pid_t pid,pidn,pidb;
	pid=fork();
	int j;
	if(pid==-1)
	{
		perror("\nError al crear proceso\n");
		exit(-1);
	}
	if(pid==0)
	{
		printf("\n Hola soy el proceso hijo: %d\n",getpid());
		printf("\n Mi padre es: %d \n",getppid());
		for(int i=0;i<3;i++)
		{
			pidn=fork();
			if(pidn==-1)
			{
				perror("\nError al crear proceso\n");
				exit(-1);
			}
			if(pidn==0)
			{
				printf("\n\t Hola soy el proceso hijo %d: %d\n",i+1,getpid());
				for(int j=0;j<2;j++)
				{
					pidb=fork();
					if(pidb==-1)
					{
						perror("\nError al crear proceso\n");
						exit(-1);
					}
					if(pidb==0)
					{
						printf("\n\t\t\t Hola soy el proceso hijo %d: %d\n",j+1,getpid());
						sleep(1);
						exit(0);
					}
					else
					{
						wait(NULL);
						printf("\n\t\t\t Mi padre es: %d\n",getpid());
					}
				}
				sleep(1);
				exit(0);
			}
			else
			{
				wait(NULL);
				printf("\n\t Mi padre es: %d\n",getpid());
			}
		}
		sleep(1);
		exit(0);
	}
	else
	{
		wait(NULL);
		printf("\n Hola soy el proceso padre de este programa: %d\n",getpid());
	}
	return 0;
}
