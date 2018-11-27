
#include "./../headers/controle.h"
#include "./../headers/spawn.h"



void Controle_joueur(SDL_Surface *ecran,char COLLISIONS[nbLin][nbCol],char MAP[nbLin][nbCol], TANK* joueur,int ID){
	//printf("controle"); //debug
	SDL_Surface* surface;
	SDL_Rect previous; // stocke la pos avant appuit pour rebliter dessus


	switch(ID)
	{
		case 1: // Flèche haut

			if(COLLISIONS[(joueur->position.y-28)/28][(joueur->position.x)/28] != 'C'){ // si pas de collision au dessus
				printf("\n Pas de collision sur x: %d y: %d",(joueur->position.x)/28,(joueur->position.y-28)/28); //debug
				joueur->direction = 'N'; // direction Nord
				previous = joueur->position; // on stocke la position pour reblitter
				joueur->position.y = (joueur->position.y -28); // on se déplace
				joueur->image = IMG_Load("sprites/joueur/haut.png"); // on chargele new image joueur
				SDL_BlitSurface(joueur->image, NULL, ecran,&joueur->position);// on blitte la nouvelle position
				COLLISIONS[joueur->position.y/28][joueur->position.x/28]='C'; // on place une collision sur la position du joueur
				COLLISIONS[previous.y/28][previous.x/28]='F'; // on retire une collision sur l'ancienne position du joueur

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

			}else{
				printf("\n COLLISION sur x: %d y: %d",(joueur->position.x)/28,(joueur->position.y-28)/28); //debug
				previous = joueur->position;

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

				joueur->direction = 'N'; // direction Nord
				joueur->image = IMG_Load("sprites/joueur/haut.png"); // on chargele new image joueur
				SDL_BlitSurface(joueur->image, NULL, ecran,&joueur->position);// on blitte la nouvelle image


			}

			break;



		case 2: // Flèche bas
			if(COLLISIONS[(joueur->position.y+28)/28][(joueur->position.x)/28] != 'C'){ // si pas de collision en dessous
				printf("\n Pas de collision sur x: %d y: %d",(joueur->position.x)/28,(joueur->position.y+28)/28); //debug
				joueur->direction = 'S'; // direction Sud
				previous = joueur->position; // on stocke la position pour reblitter
				joueur->position.y = (joueur->position.y +28); // on se déplace
				joueur->image = IMG_Load("sprites/joueur/bas.png"); // on chargele new image joueur
				SDL_BlitSurface(joueur->image, NULL, ecran,&joueur->position);// on blitte la nouvelle position
				COLLISIONS[joueur->position.y/28][joueur->position.x/28]='C'; // on place une collision sur la position du joueur
				COLLISIONS[previous.y/28][previous.x/28]='F'; // on retire une collision sur l'ancienne position du joueur


				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}

				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

			}else{
				printf("\n COLLISION sur x: %d y: %d",(joueur->position.x)/28,(joueur->position.y+28)/28); //debug
				previous = joueur->position;

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

				joueur->direction = 'S'; // direction Sud
				joueur->image = IMG_Load("sprites/joueur/bas.png"); // on chargele new image joueur
				SDL_BlitSurface(joueur->image, NULL, ecran,&joueur->position);// on blitte la nouvelle image

			}


			break;
		case 3: // Flèche droite
			if(COLLISIONS[(joueur->position.y)/28][(joueur->position.x+28)/28] != 'C'){ // si pas de collision a droite
				printf("\n Pas de collision sur x: %d y: %d",(joueur->position.x+28)/28,(joueur->position.y)/28); //debug
				joueur->direction = 'E'; // direction Est
				previous = joueur->position; // on stocke la position pour reblitter
				joueur->position.x = (joueur->position.x +28); // on se déplace
				joueur->image = IMG_Load("sprites/joueur/droite.png"); // on chargele new image joueur
				SDL_BlitSurface(joueur->image, NULL, ecran,&joueur->position);// on blitte la nouvelle position
				COLLISIONS[joueur->position.y/28][joueur->position.x/28]='C'; // on place une collision sur la position du joueur
				COLLISIONS[previous.y/28][previous.x/28]='F'; // on retire une collision sur l'ancienne position du joueur

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

			}else{
				printf("\n COLLISION sur x: %d y: %d",(joueur->position.x+28)/28,(joueur->position.y)/28); //debug
				previous = joueur->position;

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

				joueur->direction = 'E'; // direction Est
				joueur->image = IMG_Load("sprites/joueur/droite.png"); // on chargele new image joueur
				SDL_BlitSurface(joueur->image, NULL, ecran,&joueur->position);// on blitte la nouvelle image

			}
			break;
		case 4: // Flèche gauche
			if(COLLISIONS[(joueur->position.y)/28][(joueur->position.x-28)/28] != 'C'){ // si pas de collision a gauche
				printf("\n Pas de collision sur x: %d y: %d",(joueur->position.x-28)/28,(joueur->position.y)/28); //debug
				joueur->direction = 'W'; // direction Est
				previous = joueur->position; // on stocke la position pour reblitter
				joueur->position.x = (joueur->position.x -28); // on se déplace
				joueur->image = IMG_Load("sprites/joueur/gauche.png"); // on chargele new image joueur
				SDL_BlitSurface(joueur->image, NULL, ecran,&joueur->position);// on blitte la nouvelle position
				COLLISIONS[joueur->position.y/28][joueur->position.x/28]='C'; // on place une collision sur la position du joueur
				COLLISIONS[previous.y/28][previous.x/28]='F'; // on retire une collision sur l'ancienne position du joueur

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

			}else{
				printf("\n COLLISION sur x: %d y: %d",(joueur->position.x-28)/28,(joueur->position.y)/28); //debug
				previous = joueur->position;

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

				joueur->direction = 'W'; // direction West
				joueur->image = IMG_Load("sprites/joueur/gauche.png"); // on chargele new image joueur
				SDL_BlitSurface(joueur->image, NULL, ecran,&joueur->position);// on blitte la nouvelle image

			}
			break;

			break;

	}


	SDL_Flip(ecran);
	//printf("%c", joueur->direction);

	/*	printf("\n previous x: %d y: %d",(previous.x)/28,(previous.y)/28); //debug
		printf("\n new  x: %d  y: %d",joueur->position.x/28, joueur->position.y/28); // debug
		printf("\n gommé sur x: %d , y: %d",(previous.x)/28,(previous.y)/28);//debug
		printf("\n Fin Move\n"); //debug
		*/
}

void Controle_ennemi(SDL_Surface *ecran,char COLLISIONS[nbLin][nbCol],char MAP[nbLin][nbCol], TANK* ennemi){
	SDL_Surface* surface;
	SDL_Rect previous; // stocke la pos avant appuit pour rebliter dessus

	int direction = rand()%4;


	switch(direction)
	{
		case 0: // Flèche haut

			if(COLLISIONS[(ennemi->position.y-28)/28][(ennemi->position.x)/28] != 'C'){ // si pas de collision au dessus de ennemi
				//printf("\n Pas de collision sur x: %d y: %d",(ennemi->position.x)/28,(ennemi->position.y-28)/28); //debug
				ennemi->direction = 'N'; // direction Nord
				previous = ennemi->position; // on stocke la position pour reblitter
				ennemi->position.y = (ennemi->position.y -28); // on se déplace

				switch(ennemi->lvl){ //check de lvl pour blit
					case 1:
						ennemi->image = IMG_Load("sprites/tanks/lvl1/haut.png"); // on chargele new image ennemi
						break;
					case 2:
						ennemi->image = IMG_Load("sprites/tanks/lvl2/haut.png"); // on chargele new image ennemi
						break;
					case 3:
						ennemi->image = IMG_Load("sprites/tanks/lvl3/haut.png"); // on chargele new image ennemi
						break;

				}

				SDL_BlitSurface(ennemi->image, NULL, ecran,&ennemi->position);// on blitte la nouvelle position
						COLLISIONS[ennemi->position.y/28][ennemi->position.x/28]='C'; // on place une collision sur la position de l'ennemi
						COLLISIONS[previous.y/28][previous.x/28]='F'; // on retire une collision sur l'ancienne position de l'ennemi

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

			}else{
				//printf("\n COLLISION sur x: %d y: %d",(ennemi->position.x)/28,(ennemi->position.y-28)/28); //debug
				previous = ennemi->position;

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

				ennemi->direction = 'N'; // direction Nord

				switch(ennemi->lvl){ //check de lvl pour blit
					case 1:
						ennemi->image = IMG_Load("sprites/tanks/lvl1/haut.png"); // on chargele new image ennemi
						break;
					case 2:
						ennemi->image = IMG_Load("sprites/tanks/lvl2/haut.png"); // on chargele new image ennemi
						break;
					case 3:
						ennemi->image = IMG_Load("sprites/tanks/lvl3/haut.png"); // on chargele new image ennemi
						break;

				}


				SDL_BlitSurface(ennemi->image, NULL, ecran,&ennemi->position);// on blitte la nouvelle image


			}

			break;



		case 1: // Flèche bas
			if(COLLISIONS[(ennemi->position.y+28)/28][(ennemi->position.x)/28] != 'C'){ // si pas de collision en dessous
				//printf("\n Pas de collision sur x: %d y: %d",(ennemi->position.x)/28,(ennemi->position.y+28)/28); //debug
				ennemi->direction = 'S'; // direction Sud
				previous = ennemi->position; // on stocke la position pour reblitter
				ennemi->position.y = (ennemi->position.y +28); // on se déplace

				switch(ennemi->lvl){ //check de lvl pour blit
					case 1:
						ennemi->image = IMG_Load("sprites/tanks/lvl1/bas.png"); // on chargele new image ennemi
						break;
					case 2:
						ennemi->image = IMG_Load("sprites/tanks/lvl2/bas.png"); // on chargele new image ennemi
						break;
					case 3:
						ennemi->image = IMG_Load("sprites/tanks/lvl3/bas.png"); // on chargele new image ennemi
						break;

				}

				SDL_BlitSurface(ennemi->image, NULL, ecran,&ennemi->position);// on blitte la nouvelle position
				COLLISIONS[ennemi->position.y/28][ennemi->position.x/28]='C'; // on place une collision sur la position de l'ennemi
				COLLISIONS[previous.y/28][previous.x/28]='F'; // on retire une collision sur l'ancienne position de l'ennemi

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}

				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

			}else{
				//printf("\n COLLISION sur x: %d y: %d",(ennemi->position.x)/28,(ennemi->position.y+28)/28); //debug
				previous = ennemi->position;

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

				ennemi->direction = 'S'; // direction Sud

				switch(ennemi->lvl){ //check de lvl pour blit
					case 1:
						ennemi->image = IMG_Load("sprites/tanks/lvl1/bas.png"); // on chargele new image ennemi
						break;
					case 2:
						ennemi->image = IMG_Load("sprites/tanks/lvl2/bas.png"); // on chargele new image ennemi
						break;
					case 3:
						ennemi->image = IMG_Load("sprites/tanks/lvl3/bas.png"); // on chargele new image ennemi
						break;

				}


				SDL_BlitSurface(ennemi->image, NULL, ecran,&ennemi->position);// on blitte la nouvelle image

			}


			break;
		case 2: // Flèche droite
			if(COLLISIONS[(ennemi->position.y)/28][(ennemi->position.x+28)/28] != 'C'){ // si pas de collision a droite
				//printf("\n Pas de collision sur x: %d y: %d",(ennemi->position.x+28)/28,(ennemi->position.y)/28); //debug
				ennemi->direction = 'E'; // direction Est
				previous = ennemi->position; // on stocke la position pour reblitter
				ennemi->position.x = (ennemi->position.x +28); // on se déplace

				switch(ennemi->lvl){ //check de lvl pour blit
					case 1:
						ennemi->image = IMG_Load("sprites/tanks/lvl1/droite.png"); // on chargele new image ennemi
						break;
					case 2:
						ennemi->image = IMG_Load("sprites/tanks/lvl2/droite.png"); // on chargele new image ennemi
						break;
					case 3:
						ennemi->image = IMG_Load("sprites/tanks/lvl3/droite.png"); // on chargele new image ennemi
						break;

				}


				SDL_BlitSurface(ennemi->image, NULL, ecran,&ennemi->position);// on blitte la nouvelle position
				COLLISIONS[ennemi->position.y/28][ennemi->position.x/28]='C'; // on place une collision sur la position de l'ennemi
				COLLISIONS[previous.y/28][previous.x/28]='F'; // on retire une collision sur l'ancienne position de l'ennemi
				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

			}else{
				//printf("\n COLLISION sur x: %d y: %d",(ennemi->position.x+28)/28,(ennemi->position.y)/28); //debug
				previous = ennemi->position;

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

				ennemi->direction = 'E'; // direction Est

				switch(ennemi->lvl){ //check de lvl pour blit
					case 1:
						ennemi->image = IMG_Load("sprites/tanks/lvl1/droite.png"); // on chargele new image ennemi
						break;
					case 2:
						ennemi->image = IMG_Load("sprites/tanks/lvl2/droite.png"); // on chargele new image ennemi
						break;
					case 3:
						ennemi->image = IMG_Load("sprites/tanks/lvl3/droite.png"); // on chargele new image ennemi
						break;

				}

				SDL_BlitSurface(ennemi->image, NULL, ecran,&ennemi->position);// on blitte la nouvelle image

			}
			break;
		case 3: // Flèche gauche
			if(COLLISIONS[(ennemi->position.y)/28][(ennemi->position.x-28)/28] != 'C'){ // si pas de collision a gauche
				//printf("\n Pas de collision sur x: %d y: %d",(ennemi->position.x-28)/28,(ennemi->position.y)/28); //debug
				ennemi->direction = 'W'; // direction Est
				previous = ennemi->position; // on stocke la position pour reblitter
				ennemi->position.x = (ennemi->position.x -28); // on se déplace


				switch(ennemi->lvl){ //check de lvl pour blit
					case 1:
						ennemi->image = IMG_Load("sprites/tanks/lvl1/gauche.png"); // on chargele new image ennemi
						break;
					case 2:
						ennemi->image = IMG_Load("sprites/tanks/lvl2/gauche.png"); // on chargele new image ennemi
						break;
					case 3:
						ennemi->image = IMG_Load("sprites/tanks/lvl3/gauche.png"); // on chargele new image ennemi
						break;

				}

				SDL_BlitSurface(ennemi->image, NULL, ecran,&ennemi->position);// on blitte la nouvelle position
				COLLISIONS[ennemi->position.y/28][ennemi->position.x/28]='C'; // on place une collision sur la position de l'ennemi
				COLLISIONS[previous.y/28][previous.x/28]='F'; // on retire une collision sur l'ancienne position de l'ennemi



				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

			}else{
				//printf("\n COLLISION sur x: %d y: %d",(ennemi->position.x-28)/28,(ennemi->position.y)/28); //debug
				previous = ennemi->position;

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

				ennemi->direction = 'W'; // direction West

				switch(ennemi->lvl){ //check de lvl pour blit
					case 1:
						ennemi->image = IMG_Load("sprites/tanks/lvl1/gauche.png"); // on chargele new image ennemi
						break;
					case 2:
						ennemi->image = IMG_Load("sprites/tanks/lvl2/gauche.png"); // on chargele new image ennemi
						break;
					case 3:
						ennemi->image = IMG_Load("sprites/tanks/lvl3/gauche.png"); // on chargele new image ennemi
						break;

				}


				SDL_BlitSurface(ennemi->image, NULL, ecran,&ennemi->position);// on blitte la nouvelle image

			}
			break;

			break;

	}


	SDL_Flip(ecran);
	//printf("%c", ennemi->direction);

	/*	printf("\n previous x: %d y: %d",(previous.x)/28,(previous.y)/28); //debug
		printf("\n new  x: %d  y: %d",ennemi->position.x/28, ennemi->position.y/28); // debug
		printf("\n gommé sur x: %d , y: %d",(previous.x)/28,(previous.y)/28);//debug
		printf("\n Fin Move\n"); //debug
		*/
}

void Controle_titi(SDL_Surface *ecran,char COLLISIONS[nbLin][nbCol],char MAP[nbLin][nbCol], TITI* titi){
	SDL_Surface* surface;
	SDL_Rect previous; // stocke la pos avant appuit pour rebliter dessus
	int direction = rand()%4;


	switch(direction)
	{
		case 0: // Flèche haut

			if(COLLISIONS[(titi->position.y-28)/28][(titi->position.x)/28] != 'C'){ // si pas de collision au dessus de titi
				//printf("\n Pas de collision sur x: %d y: %d",(titi->position.x)/28,(titi->position.y-28)/28); //debug
				titi->direction = 'N'; // direction Nord
				previous = titi->position; // on stocke la position pour reblitter
				titi->position.y = (titi->position.y -28); // on se déplace

				SDL_BlitSurface(titi->image, NULL, ecran,&titi->position);// on blitte la nouvelle position
						COLLISIONS[titi->position.y/28][titi->position.x/28]='C'; // on place une collision sur la position de titi
						COLLISIONS[previous.y/28][previous.x/28]='F'; // on retire une collision sur l'ancienne position de titi

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

			}else{
				//printf("\n COLLISION sur x: %d y: %d",(titi->position.x)/28,(titi->position.y-28)/28); //debug
				previous = titi->position;

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

				titi->direction = 'N'; // direction Nord


				SDL_BlitSurface(titi->image, NULL, ecran,&titi->position);// on blitte la nouvelle image

			break;



		case 1: // Flèche bas
			if(COLLISIONS[(titi->position.y+28)/28][(titi->position.x)/28] != 'C'){ // si pas de collision en dessous
				//printf("\n Pas de collision sur x: %d y: %d",(titi->position.x)/28,(titi->position.y+28)/28); //debug
				titi->direction = 'S'; // direction Sud
				previous = titi->position; // on stocke la position pour reblitter
				titi->position.y = (titi->position.y +28); // on se déplace

				SDL_BlitSurface(titi->image, NULL, ecran,&titi->position);// on blitte la nouvelle position
				COLLISIONS[titi->position.y/28][titi->position.x/28]='C'; // on place une collision sur la position de titi
				COLLISIONS[previous.y/28][previous.x/28]='F'; // on retire une collision sur l'ancienne position de titi

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}

				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

			}else{
				//printf("\n COLLISION sur x: %d y: %d",(titi->position.x)/28,(titi->position.y+28)/28); //debug
				previous = titi->position;

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

				titi->direction = 'S'; // direction Sud

				SDL_BlitSurface(titi->image, NULL, ecran,&titi->position);// on blitte la nouvelle image

			}


			break;
		case 2: // Flèche droite
			if(COLLISIONS[(titi->position.y)/28][(titi->position.x+28)/28] != 'C'){ // si pas de collision a droite
				//printf("\n Pas de collision sur x: %d y: %d",(titi->position.x+28)/28,(titi->position.y)/28); //debug
				titi->direction = 'E'; // direction Est
				previous = titi->position; // on stocke la position pour reblitter
				titi->position.x = (titi->position.x +28); // on se déplace



				SDL_BlitSurface(titi->image, NULL, ecran,&titi->position);// on blitte la nouvelle position
				COLLISIONS[titi->position.y/28][titi->position.x/28]='C'; // on place une collision sur la position de titi
				COLLISIONS[previous.y/28][previous.x/28]='F'; // on retire une collision sur l'ancienne position de titi
				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

			}else{
				//printf("\n COLLISION sur x: %d y: %d",(titi->position.x+28)/28,(titi->position.y)/28); //debug
				previous = titi->position;

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

				titi->direction = 'E'; // direction Est


				SDL_BlitSurface(titi->image, NULL, ecran,&titi->position);// on blitte la nouvelle image

			}
			break;
		case 3: // Flèche gauche
			if(COLLISIONS[(titi->position.y)/28][(titi->position.x-28)/28] != 'C'){ // si pas de collision a gauche
				//printf("\n Pas de collision sur x: %d y: %d",(titi->position.x-28)/28,(titi->position.y)/28); //debug
				titi->direction = 'W'; // direction Est
				previous = titi->position; // on stocke la position pour reblitter
				titi->position.x = (titi->position.x -28); // on se déplace


				SDL_BlitSurface(titi->image, NULL, ecran,&titi->position);// on blitte la nouvelle position
				COLLISIONS[titi->position.y/28][titi->position.x/28]='C'; // on place une collision sur la position de  titi
				COLLISIONS[previous.y/28][previous.x/28]='F'; // on retire une collision sur l'ancienne position de titi



				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

			}else{
				//printf("\n COLLISION sur x: %d y: %d",(titi->position.x-28)/28,(titi->position.y)/28); //debug
				previous = titi->position;

				if(MAP[(previous.y)/28][(previous.x)/28]=='H'){ // si previous etait de l'herbe
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
				}			

				if(MAP[(previous.y)/28][(previous.x)/28]=='P'){// si previous etait un pont
					surface=IMG_Load("sprites/sol/pont.png");// on charge un pont
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le pont sur previous'
				}


				if(MAP[(previous.y)/28][(previous.x)/28]=='O'){ // si previous etait un trou d'obus
					surface=IMG_Load("sprites/sol/herbe.png");// on charge de l'herbe
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte l'herbe sur previous'
					surface=IMG_Load("sprites/animation/trou.png");// on charge un trou
					SDL_BlitSurface(surface, NULL, ecran,&previous);// on blitte le trou sur previous'

				}

				titi->direction = 'W'; // direction West

				SDL_BlitSurface(titi->image, NULL, ecran,&titi->position);// on blitte la nouvelle image

			}
			break;

			break;

	}


	SDL_Flip(ecran);

}

}
