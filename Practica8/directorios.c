#include "directorios.h"

/* 
 * Status de retorno:
 *  0 -> Directorio creado correctamente
 * -1 -> Ocurrió un error al intentar crear el directorio
 *  1 -> El directorio ya existe
 * */

int crearDirectorio(char* nombreDirectorio) {
    if(!strlen(nombreDirectorio)) return -1;
    if(!checarExistenciaDirectorio(nombreDirectorio))
    {
       return mkdir(nombreDirectorio, S_IRUSR | S_IRGRP | S_IROTH | S_IXUSR | S_IXGRP | S_IXOTH);
    }
    return 1;
}

/* 
 * Status de retorno:
 *  0 -> Directorio eliminado correctamente
 * -1 -> Ocurrió un error al intentar eliminar el directorio
 * */

int eliminarDirectorio(char* nombreDirectorio) {
    if(!strlen(nombreDirectorio)) return -1;
    if(checarExistenciaDirectorio(nombreDirectorio))
    {
        char instruccion[200] = "rm -rf ./";
        strcat(instruccion, nombreDirectorio);
        strcat(instruccion, "/");
        puts(instruccion);
        system(instruccion);
        return 0;
    }
    return -1;   
}

/* 
 * Status de retorno:
 *  0 -> Directorio no existente
 *  1 -> Directorio existente
 * -1 -> Ocurrió un error al checar existencia de directorio
 * */

int checarExistenciaDirectorio(char* nombreArchivo) {
    DIR *dir = NULL;
    struct dirent *info;

    /* Comenzamos a leer el directorio actual */
    dir = opendir(".");
    if(!dir) return -1;
    while((info = readdir(dir)) != NULL) {
        if(!strcmp(info->d_name, nombreArchivo)) {
           return 1; 
        }
    }
    return 0;
}

