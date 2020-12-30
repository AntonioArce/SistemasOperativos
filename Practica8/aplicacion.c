#include "aplicacion.h"

void menuprincipal()
{
  int opcion, repetir;
  do
  {
        system("clear");
        puts("========= Bienvenido al menu principal =========\n\n");
        puts("1.- Crear Archivo");
        puts("2.- Modificar Archivos");
        puts("3.- Buscar Archivo");
        puts("4.- Salir");
        puts("¿Que accion deseas realizar? ");
        __fpurge(stdin);
        scanf("%d", &opcion);
        seleccionDeOpcion(opcion);
        puts("Ingresa 1 para volver al menu principal o ingresa 0 para salir del sistema");
        __fpurge(stdin);
        scanf("%d", &repetir);
  }
  while (repetir);
}
void seleccionDeOpcion(char op)
{
  switch(op)
  {
    case 1: //Crear Archivo
    break;
    case 2: //Modificar Archivo
    break;
    case 3: //Borrar Archivo
    break;
    case 4: //Salir del sistema
      exit(EXIT_SUCCESS);
    break;
    default:
      puts("Opcion no valida");
    break;
  }
}