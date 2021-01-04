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
        puts("3.- Eliminar Archivo");
        puts("4.- Listar Directorios");
        puts("5.- Salir del sistema");
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
        modificacionArchivo();
    break;
    case 3: //Borrar Archivo
        borradoArchivo();
    break;
    case 4: //Lista el directorio actual y el contenido de los directorios
        listarContenido();
    break;
    case 5: //Salir del sistema
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


void borradoArchivo()
{
    char nombreArchivo[100];
    int status = 0;
    int opc;

    listarContenido();

    puts("Desea eliminar un directorio o un archivo");
    puts("1.- Directorio");
    puts("2.- Archivo");
    scanf("%d",&opc);

    switch(opc)
    {
        case 1:
            puts("Ingrese el nombre del directorio a eliminar");
            __fpurge(stdin);
            fgets(nombreArchivo, 100, stdin);

            status = eliminarDirectorio(nombreArchivo);

            if(status == 0)
                puts("Directorio eliminado satisfactoriamente");
            else
                puts("Hubo un error al eliminar directorio");
        break;
        case 2:
            puts("Ingrese el nombre del archivo a eliminar");
            __fpurge(stdin);
            fgets(nombreArchivo, 100, stdin);

            status = borrarArchivo(nombreArchivo);

            if(status == 0)
                puts("Archivo eliminado satisfactoriamente");
            else
                puts("Hubo un error al eliminar archivo");
        break;
    }
}
void modificacionArchivo()
{
    char nombreArchivo[100];
    char buscar[200];      // texto a buscar
    char reemplazar[200];  // reemplazar por

    int status = 0;
    int opc;

    listarContenido();

    puts("Desea modificar un archivo dentro de un directorio o un archivo de la raiz");
    puts("1.- Directorio");
    puts("2.- Archivo");
    scanf("%d",&opc);

    switch(opc)
    {
        case 1:
            puts("Ingrese el nombre del directorio para modificar su archivo");
            __fpurge(stdin);
            fgets(nombreArchivo, 100, stdin);
            
            puts("Ingresa el texto a buscar: ");
            __fpurge(stdin);
            fgets(buscar, 100, stdin);

            puts("Ingresa el texto para reemplazarlo:");
            __fpurge(stdin);
            fgets(reemplazar, 100, stdin);

            status = modificarArchivoDirectorio(nombreArchivo,buscar,reemplazar);

            if(status == 1)
                puts("Archivo en directorio modificado con exito");
            else
                puts("Error al modificar archivo");

        break;
        case 2:
            puts("Ingrese el nombre del archivo a modificar");
            __fpurge(stdin);
            fgets(nombreArchivo, 100, stdin);

            puts("Ingresa el texto a buscar: ");
            __fpurge(stdin);
            fgets(buscar, 100, stdin);

            puts("Ingresa el texto para reemplazarlo:");
            __fpurge(stdin);
            fgets(reemplazar, 100, stdin);

            status = modificarArchivo(nombreArchivo,buscar,reemplazar);

            if(status == 1)
                puts("Archivo modificado con exito");
            else
                puts("Error al modificar archivo");
        break;
    }
}