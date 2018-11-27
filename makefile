PROJET :  COMPILATION LANCEMENT NETTOYAGE

controle.o : ./headers/controle.h
	gcc -c ./sources/controle.c  -w -lSDL -lSDL_image `sdl-config --cflags --libs`

load.o : ./headers/load.h
	gcc -c ./sources/load.c -w -lSDL -lSDL_image `sdl-config --cflags --libs`

spawn.o : ./headers/spawn.h
	gcc -c ./sources/spawn.c -w -lSDL -lSDL_image `sdl-config --cflags --libs`

tir.o : ./headers/tir.h
	gcc -c ./sources/tir.c -w -lSDL -lSDL_image `sdl-config --cflags --libs`


main.o : ./headers/controle.h ./headers/load.h ./headers/spawn.h ./headers/tir.h 
	gcc -c ./sources/main.c -w -lSDL -lSDL_image `sdl-config --cflags --libs`

COMPILATION : main.o controle.o load.o spawn.o tir.o
	gcc -o TankPixel main.o controle.o load.o spawn.o tir.o -w  -lSDL -lSDL_image `sdl-config --cflags --libs`
	clear


LANCEMENT :
	-./TankPixel

NETTOYAGE : 
	rm *.o
	clear
