a.out: archivos.o directorios.o aplicacion.o programa81.o
	gcc archivos.o directorios.o aplicacion.o programa81.o -Wextra -Wall

archivos.o: archivos.c
	gcc -c archivos.c -Wall -Wextra

directorios.o: directorios.c
	gcc -c directorios.c -Wall -Wextra

aplicacion.o: aplicacion.c
	gcc -c aplicacion.c -Wall -Wextra

programa81.o: programa81.c
	gcc -c programa81.c -Wall -Wextra

run: a.out
	./a.out

clear:
	rm a.out aplicacion.o programa81.o archivos.o directorios.o
