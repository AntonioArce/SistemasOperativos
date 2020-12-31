#ifndef __ARCHIVOS_H__
#define __ARCHIVOS_H__

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int crearArchivo(char[], char[], int);
int modificarArchivo(char*);
int eliminarArchivo(char*);
int checarExistenciaArchivo(char*);

#endif
