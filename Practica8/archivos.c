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
    if(nombreArchivo[strlen(nombreArchivo) - 1] == '\n') nombreArchivo[strlen(nombreArchivo) - 1] = '\0';
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

/*
 * Status de retorno
 *  0 -> archivo eliminado 
 *  1 -> No se pudo eliminar archivo
 * */

int borrarArchivo(char* nombreArchivo)
{
    int status = checarExistenciaArchivo(nombreArchivo);

    if(status == 1)
    {
        if(remove(nombreArchivo) == 0)
            return 0;
    }
    else if(status == 0)
        return 1;
        

}
/*
 * Status de retorno
 *  1 -> archivo modificado 
 *  0 -> No se pudo eliminar archivo
 * */
int modificarArchivoDirectorio(char *nombreArchivo, char *buscar, char *reemplazar)
{
    
}
/*
 * Status de retorno
 *  1 -> archivo modificado 
 *  0 -> No se pudo eliminar archivo
 * */
int modificarArchivo(char *nombreArchivo,char *buscar,char *reemplazar)
{
    int status = checarExistenciaArchivo(nombreArchivo);
    char prueba[100];
    char delimitador[]=" ";
    char nuevalinea[200];
    int pos, i;

    if(status == 1)
    {
        if(buscar[strlen(buscar) - 1] == '\n') buscar[strlen(buscar) - 1] = '\0';
        if(reemplazar[strlen(reemplazar) - 1] == '\n') reemplazar[strlen(reemplazar) - 1] = '\0';
        FILE *archivo = NULL;
        FILE *archivotemp = NULL;

        archivo = fopen(nombreArchivo,"r+");
        archivotemp = fopen("temporal.txt","w+");


        if(archivo==NULL) //no se pudo abrir alguno de los 2
        {
            puts("Error al abrir archivo");
            return -1; 
        }

        //fread(prueba,strlen(prueba),1,archivo);

        //modificar linea a linea
        fgets(prueba,100,archivo);
        char *token = strtok(prueba, delimitador);
        while(token != NULL)
        {
            if(strcmp(token,buscar)==0)
            {
                strcpy(token,reemplazar);
                strcat(nuevalinea,token);
            }
            else
            {
                strcat(nuevalinea, " ");
                strcat(nuevalinea,token);
                strcat(nuevalinea, " ");
            }
            token = strtok(NULL, delimitador);
        }
        __fpurge(stdin);
        fwrite(nuevalinea,strlen(nuevalinea)*sizeof(char),1,archivotemp);
        fclose(archivo);
        fclose(archivotemp);

        remove(nombreArchivo);
        rename("temporal.txt",nombreArchivo);

        return 1;
        
    }
    else if(status == 0)
        return 0;
}
void listarContenido()
{
    system("tree");   
}
