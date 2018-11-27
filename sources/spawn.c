#include "./../headers/spawn.h"



TANK* Spawn_joueur(SDL_Surface *ecran, char COLLISIONS[nbLin][nbCol]){
	int X;
	int Y;

	TANK *joueur;

	joueur = malloc(sizeof(TANK));

	if (joueur == NULL)
	{
		printf("\nProbleme memoire!");
		exit(-1);
	}else{printf("\n Spawn joueur OK!\n");} //debug


	joueur->image = IMG_Load("sprites/joueur/haut.png");
	joueur->direction = 'N';
	joueur->lvl = 2;
	joueur->vie =1;

	do{ 

		X = rand()%40;
		Y = rand()%20;

		printf("\nSpawn x: %d y: %d\n",X,Y); // pour debug



		joueur->position.x = X*28;
		joueur->position.y = Y*28;

		//	printf("\nPosition pixel x: %d y: %d\n",joueur->position.x,joueur->position.y); // pour debug

	}while(COLLISIONS[Y][X] == 'C');

	SDL_BlitSurface(joueur->image, NULL, ecran,&joueur->position);
	SDL_Flip(ecran);

	return joueur;
}

TANK* Spawn_Ennemi(SDL_Surface *ecran, char COLLISIONS[nbLin][nbCol], int niveau){
	int X;
	int Y;

	TANK *ennemi;

	ennemi = malloc(sizeof(TANK));

	if (ennemi == NULL)
	{
		printf("\nProbleme memoire!");
		exit(-1);
	}else{printf("\n Spawn ennemi OK!\n");} //debug

	ennemi->lvl = niveau;
	ennemi->vie = 1;
	ennemi->direction = 'N';

	switch(niveau){

		case 1:
			ennemi->image = IMG_Load("sprites/tanks/lvl1/haut.png");
			break;
		case 2:
			ennemi->image = IMG_Load("sprites/tanks/lvl2/haut.png");
			break;
		case 3:
			ennemi->image = IMG_Load("sprites/tanks/lvl3/haut.png");
			break;

	}




	do{ 

		X = rand()%40;
		Y = rand()%20;

		printf("\nSpawn ennemi x: %d y: %d\n",X,Y); // pour debug



		ennemi->position.x = X*28;
		ennemi->position.y = Y*28;

		//	printf("\nPosition pixel x: %d y: %d\n",joueur->position.x,joueur->position.y); // pour debug

	}while(COLLISIONS[Y][X] == 'C');

	SDL_BlitSurface(ennemi->image, NULL, ecran,&ennemi->position);
	SDL_Flip(ecran);

	return ennemi;
}


OBUS* Init_Obus(SDL_Surface *ecran,char MAP[nbLin][nbCol],TANK* joueur){

	OBUS *obus_joueur;

	obus_joueur = malloc(sizeof(OBUS));

	if (joueur == NULL)
	{
		printf("\nProbleme memoire!");
		exit(-1);
	}else{printf("\n Init obus OK!\n");} //debug


	return obus_joueur;
}

TITI* Spawn_titi(SDL_Surface *ecran,char MAP[nbLin][nbCol]){

	TITI *titi;

	titi = malloc(sizeof(TITI));

	if (titi == NULL)
	{
		printf("\nProbleme memoire!");
		exit(-1);
	}else{printf("\n Spawn titi OK!\n");} //debug


	titi->image = IMG_Load("sprites/obstacle/titi.png");
	titi->vie =1;
	titi->position.x = 31*28;
	titi->position.y = 23*28;
	titi->direction='N';
	//MAP[titi->position.y/28][titi->position.x/28] = 'T'; // défini la position initiale de titi
	SDL_BlitSurface(titi->image, NULL, ecran,&titi->position);
	SDL_Flip(ecran);

	return titi;

}
