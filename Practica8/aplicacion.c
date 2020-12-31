#include "aplicacion.h"
#include "archivos.h"

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
        creacionArchivo();
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

void creacionArchivo() {
    char nombreArchivo[100];
    char contenidoArchivo[500];
    int status = 0;
    int directorio = 0;
    puts("Ingrese el nombre del archivo");
    __fpurge(stdin);
    fgets(nombreArchivo, 100, stdin);
    puts("Ingresa el contenido del archivo");
    __fpurge(stdin);
    fgets(contenidoArchivo, 500, stdin);
    do {
        puts("¿Quieres crear un directorio especial para este archivo?\n1 -> Si\n0 -> No");
        __fpurge(stdin);
        scanf("%d", &directorio);
    }while(directorio < 0 || directorio > 1);
    status = crearArchivo(nombreArchivo, contenidoArchivo, directorio);
    if(!status) {
        puts("Archivo creado correctamente");
    }else if(status == 1){
        puts("Archivo ya existente");
    }else if(status == -1) {
        puts("Ocurrio un error");
    }
}
