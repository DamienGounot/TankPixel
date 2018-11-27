#ifndef _CONTROLE_H_
#define _CONTROLE_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <unistd.h>

#define nbLin 26 // nbcases hauteur du plateau
#define nbCol 45// nb cases largeur du plateau


void Controle_joueur();
void Controle_ennemi();
void Controle_titi();
int Check_titi();

#endif
