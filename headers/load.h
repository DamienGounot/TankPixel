#ifndef _LOAD_H_
#define _LOAD_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <unistd.h>

#define nbLin 26 // nbcases hauteur du plateau
#define nbCol 45// nb cases largeur du plateau

void LoadMap();
void LoadCol();
void LoadDest();

#endif
