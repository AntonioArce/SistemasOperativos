#include "archivos.h"
#include "directorios.h"
/*
 * Status de retorno:
 *  0 -> Archivo creado correctamente
 *  1 -> Archivo ya existente
 * -1 -> Ocurrió un problema al intentar crear el archivo
 * */

int crearArchivo(char nombreArchivo[], char contenidoArchivo[], int directorio) {
    char rutaArchivo[200] = "./";
    char rutaDirectorio[200] = "./";
    char instruccion[400] = "mv ";
    FILE *archivo = NULL;
    if(nombreArchivo[strlen(nombreArchivo) - 1] == '\n') nombreArchivo[strlen(nombreArchivo) - 1] = '\0';
    strcat(rutaArchivo, nombreArchivo);
    strcat(rutaArchivo, ".txt");
    archivo = fopen(rutaArchivo, "r");
    if(archivo) {
        fclose(archivo);
        return 1;
    }else {
        archivo = fopen(rutaArchivo, "w+");
        if(!archivo) return -1;
        fwrite(contenidoArchivo, strlen(contenidoArchivo) * sizeof(char) , 1, archivo);
    }
 
    if(directorio && !checarExistenciaDirectorio(nombreArchivo)) {
        crearDirectorio(nombreArchivo);
        strcat(rutaDirectorio, nombreArchivo);
        strcat(rutaDirectorio, "/");
        strcat(instruccion, rutaArchivo);
        strcat(instruccion, " ");
        strcat(instruccion, rutaDirectorio);
        puts(instruccion);
        system(instruccion);
    }else if(directorio && checarExistenciaDirectorio(nombreArchivo)) {
        // Agregas la función de eliminar archivo cuando la implementes 
        fclose(archivo);
        return 1;
    }
    fclose(archivo);
    return 0;
}

/*
 * Status de retorno
 *  0 -> Archivo no existente
 *  1 -> Archivo existente
 * -1 -> Ocurrió un error al checar existencia de directorio 
 * */

int checarExistenciaArchivo(char* nombreArchivo) {
    DIR *archivo = NULL;
    struct dirent *info;
    strcat(nombreArchivo, ".txt");
    archivo = opendir(".");
    if(!archivo) return -1;
    while((info = readdir(archivo)) != NULL) {
        if(!strcmp(info->d_name, nombreArchivo)) {
            return 1;
        }
    }
    return 0;
}
