#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include<sys/types.h>

int main() 
{
    int a = 0;
    while(a < 10)
    {
        pid_t pid = fork();
        if(pid == -1) 
        {
            perror("Error al crear el proceso");
            exit(-1);
        }
        if(!pid) 
        {
            printf("Soy el hijo %d del proceso padre y tengo el pid %d\n", a, getpid());
            printf("Mi proceso padre es: %d\n", getppid());
            sleep(5);
            exit(0);
        }
        a++;
        wait(NULL);
    }
    printf("Soy el proceso padre y tengo el pid %d\n", getpid());
    printf("Mi proceso padre es: %d\n", getppid());
    return 0;

}
