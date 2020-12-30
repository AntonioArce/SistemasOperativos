#ifndef __DIRECOTORIOS_H__
#define __DIRECTORIOS_H__

#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int crearDirectorio(char*);
int checarExistenciaDirectorio(char*);
int eliminarDirectorio(char*);

#endif
