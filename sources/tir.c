#include "./../headers/tir.h"
#include "./../headers/spawn.h"



void Tir_easy(SDL_Surface *ecran, char MAP[nbLin][nbCol], TANK* joueur,OBUS* obus_joueur, char COLLISION[nbLin][nbCol], char DESTRUCTION[nbLin][nbCol],TANK* tank1,TANK* tank2,TANK* tank3,TITI* titi){

	SDL_Surface* surface; // surface a rebliter
	//SDL_Rect previous; // stocke la pos avant appuit pour rebliter dessus
	//SDL_Rect next; // stock la pos suivante pour calcul



	surface =IMG_Load("sprites/sol/herbe.png");
	obus_joueur->image = IMG_Load("sprites/animation/explosion.png");// on charge une explosion

	switch(joueur->direction){
		case 'N':	
			obus_joueur->position = joueur->position;
			obus_joueur->position.y = joueur->position.y -(28*joueur->lvl); // la portée est liée au lvl du tank

			break;

		case 'S':
			obus_joueur->position = joueur->position;
			obus_joueur->position.y = joueur->position.y +(28*joueur->lvl);

			break;

		case 'E':
			obus_joueur->position = joueur->position;
			obus_joueur->position.x = joueur->position.x +(28*joueur->lvl);

			break;

		case'W':
			obus_joueur->position = joueur->position;
			obus_joueur->position.x = joueur->position.x -(28*joueur->lvl);	


			break;


	}


	if(DESTRUCTION[(obus_joueur->position.y/28)][(obus_joueur->position.x/28)] =='D' && obus_joueur->position.y >0 && obus_joueur->position.x >0 ){ // si obus sur case destructible

		SDL_BlitSurface(surface,NULL,ecran,&obus_joueur->position); // blit pour effacer
		SDL_BlitSurface(obus_joueur->image,NULL,ecran,&obus_joueur->position); // blit l 'explosion



		COLLISION[(obus_joueur->position.y/28)][(obus_joueur->position.x/28)] = 'F'; // on vire la collision
		MAP[(obus_joueur->position.y/28)][(obus_joueur->position.x/28)] = 'O'; // on MAJ la map


		SDL_Flip(ecran);
		SDL_Delay(7);
		SDL_BlitSurface(surface,NULL,ecran,&obus_joueur->position); // blit pour effacer
		obus_joueur->image = IMG_Load("sprites/animation/trou.png");// on charge un trou
		SDL_BlitSurface(obus_joueur->image,NULL,ecran,&obus_joueur->position); // blit le trou
		SDL_Flip(ecran);

		if(obus_joueur->position.x == tank1->position.x && obus_joueur->position.y == tank1->position.y){ tank1->vie = 0;}
		if(obus_joueur->position.x == tank2->position.x && obus_joueur->position.y == tank2->position.y){ tank2->vie = 0;}
		if(obus_joueur->position.x == tank3->position.x && obus_joueur->position.y == tank3->position.y){ tank3->vie = 0;}
		if(obus_joueur->position.x == titi->position.x && obus_joueur->position.y == titi->position.y){ titi->vie = 0;}
	}

	printf("\nSpawn Obus : x %d: y: %d\n",(obus_joueur->position.y/28),(obus_joueur->position.x)/28); // debug


	SDL_Flip(ecran);

}


void Tir_hard(SDL_Surface *ecran, char MAP[nbLin][nbCol], TANK* joueur,OBUS* obus_joueur, char COLLISION[nbLin][nbCol], char DESTRUCTION[nbLin][nbCol],TANK* tank1,TANK* tank2,TANK* tank3,TANK* tank4,TANK* tank5,TANK* tank6,TANK* tank7,TANK* tank8,TANK* tank9,TITI* titi){

	SDL_Surface* surface; // surface a rebliter
	//SDL_Rect previous; // stocke la pos avant appuit pour rebliter dessus
	//SDL_Rect next; // stock la pos suivante pour calcul



	surface =IMG_Load("sprites/sol/herbe.png");
	obus_joueur->image = IMG_Load("sprites/animation/explosion.png");// on charge une explosion

	switch(joueur->direction){
		case 'N':	
			obus_joueur->position = joueur->position;
			obus_joueur->position.y = joueur->position.y -(28*joueur->lvl); // la portée est liée au lvl du tank

			break;

		case 'S':
			obus_joueur->position = joueur->position;
			obus_joueur->position.y = joueur->position.y +(28*joueur->lvl);

			break;

		case 'E':
			obus_joueur->position = joueur->position;
			obus_joueur->position.x = joueur->position.x +(28*joueur->lvl);

			break;

		case'W':
			obus_joueur->position = joueur->position;
			obus_joueur->position.x = joueur->position.x -(28*joueur->lvl);	


			break;


	}


	if(DESTRUCTION[(obus_joueur->position.y/28)][(obus_joueur->position.x/28)] =='D' && obus_joueur->position.y >0 && obus_joueur->position.x >0 ){ // si obus sur case destructible

		SDL_BlitSurface(surface,NULL,ecran,&obus_joueur->position); // blit pour effacer
		SDL_BlitSurface(obus_joueur->image,NULL,ecran,&obus_joueur->position); // blit l 'explosion




		COLLISION[(obus_joueur->position.y/28)][(obus_joueur->position.x/28)] = 'F'; // on vire la collision
		MAP[(obus_joueur->position.y/28)][(obus_joueur->position.x/28)] = 'O'; // on MAJ la map


		SDL_Flip(ecran);
		SDL_Delay(7);
		SDL_BlitSurface(surface,NULL,ecran,&obus_joueur->position); // blit pour effacer
		obus_joueur->image = IMG_Load("sprites/animation/trou.png");// on charge un trou
		SDL_BlitSurface(obus_joueur->image,NULL,ecran,&obus_joueur->position); // blit le trou
		SDL_Flip(ecran);

		if(obus_joueur->position.x == tank1->position.x && obus_joueur->position.y == tank1->position.y){ tank1->vie = 0;}
		if(obus_joueur->position.x == tank2->position.x && obus_joueur->position.y == tank2->position.y){ tank2->vie = 0;}
		if(obus_joueur->position.x == tank3->position.x && obus_joueur->position.y == tank3->position.y){ tank3->vie = 0;}
		if(obus_joueur->position.x == tank4->position.x && obus_joueur->position.y == tank4->position.y){ tank4->vie = 0;}
		if(obus_joueur->position.x == tank5->position.x && obus_joueur->position.y == tank5->position.y){ tank5->vie = 0;}
		if(obus_joueur->position.x == tank6->position.x && obus_joueur->position.y == tank6->position.y){ tank6->vie = 0;}
		if(obus_joueur->position.x == tank7->position.x && obus_joueur->position.y == tank7->position.y){ tank7->vie = 0;}
		if(obus_joueur->position.x == tank8->position.x && obus_joueur->position.y == tank8->position.y){ tank8->vie = 0;}
		if(obus_joueur->position.x == tank9->position.x && obus_joueur->position.y == tank9->position.y){ tank9->vie = 0;}
		if(obus_joueur->position.x == titi->position.x && obus_joueur->position.y == titi->position.y){ titi->vie = 0;}
	}

	printf("\nSpawn Obus : x %d: y: %d\n",(obus_joueur->position.y/28),(obus_joueur->position.x)/28); // debug


	SDL_Flip(ecran);

}



void Tir_ennemi(SDL_Surface *ecran, char MAP[nbLin][nbCol], TANK* ennemi,OBUS* obus_ennemi, char COLLISION[nbLin][nbCol], char DESTRUCTION[nbLin][nbCol],TANK* joueur,TITI* titi){ 

	SDL_Surface* surface; // surface a rebliter
	//SDL_Rect previous; // stocke la pos avant appuit pour rebliter dessus
	//SDL_Rect next; // stock la pos suivante pour calcul

	int tir =rand()%100 +1;



	surface =IMG_Load("sprites/sol/herbe.png");
	obus_ennemi->image = IMG_Load("sprites/animation/explosion.png");// on charge une explosion

	if(tir <75 ){

		printf("Tir %d",tir);

		switch(ennemi->direction){
			case 'N':	
				obus_ennemi->position = ennemi->position;
				obus_ennemi->position.y = ennemi->position.y -(28*ennemi->lvl); // la portée est liée au lvl du tank

				break;

			case 'S':
				obus_ennemi->position = ennemi->position;
				obus_ennemi->position.y = ennemi->position.y +(28*ennemi->lvl);

				break;

			case 'E':
				obus_ennemi->position = ennemi->position;
				obus_ennemi->position.x = ennemi->position.x +(28*ennemi->lvl);

				break;

			case'W':
				obus_ennemi->position = ennemi->position;
				obus_ennemi->position.x = ennemi->position.x -(28*ennemi->lvl);	


				break;


		}




		if(DESTRUCTION[(obus_ennemi->position.y/28)][(obus_ennemi->position.x/28)]=='D' && obus_ennemi->position.x >=0 && obus_ennemi->position.y >=0){ // si obus sur case destructible

			SDL_BlitSurface(surface,NULL,ecran,&obus_ennemi->position); // blit pour effacer
			SDL_BlitSurface(obus_ennemi->image,NULL,ecran,&obus_ennemi->position); // blit l'explosion
			COLLISION[(obus_ennemi->position.y/28)][(obus_ennemi->position.x/28)] = 'F'; // on vire la collision
			MAP[(obus_ennemi->position.y/28)][(obus_ennemi->position.x/28)] = 'O'; // on MAJ la map

			SDL_Flip(ecran);
			SDL_BlitSurface(surface,NULL,ecran,&obus_ennemi->position); // blit pour effacer
			obus_ennemi->image = IMG_Load("sprites/animation/trou.png");// on charge un trou
			SDL_BlitSurface(obus_ennemi->image,NULL,ecran,&obus_ennemi->position); // blit le trou
			SDL_Flip(ecran);

			if(joueur->position.x == obus_ennemi->position.x && joueur->position.y == obus_ennemi->position.y){ // si position obus = position joueur
				joueur->vie = 0; // le joueur décède
			}

			if(titi->position.x == obus_ennemi->position.x && titi->position.y == obus_ennemi->position.y){ // si position obus = position titi
				titi->vie = 0; // titi décède
			}

		}

		printf("\nSpawn Obus : x %d: y: %d \n",obus_ennemi->position.x/28,obus_ennemi->position.y/28); // debug

	}



	SDL_Flip(ecran);

}
