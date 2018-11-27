#ifndef _SPAWN_H_
#define _SPAWN_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <unistd.h>

#define nbLin 26 // nbcases hauteur du plateau
#define nbCol 45// nb cases largeur du plateau


typedef struct tank                 //  structure tank
{
	int lvl;     // 1,2 ou 3
	char direction;   // Nord,Sud,Est,West  (N,S,E,W)
	SDL_Rect position;      //position (x.y)  
	SDL_Surface* image;// .png
	int vie; // 1 ou 0 pour savoir si le tank est en vie ou mort

} TANK;

typedef struct obus  // structure obus
{

	SDL_Rect position;      //position (x.y)  
	SDL_Surface* image;// .png de l'obus


} OBUS;

typedef struct titi  // structure titi
{

	SDL_Rect position;      //position (x.y)  
	SDL_Surface* image;// .png de titi
	int vie; // si titi en vie ou mort
	char direction; // pour faire s'enfuir titi


} TITI;


OBUS* Init_Obus();
TANK* Spawn_Ennemi();
TANK* Spawn_joueur();
TITI* Spawn_titi();

#endif
