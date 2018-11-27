#include "./../headers/controle.h"
#include "./../headers/load.h"
#include "./../headers/spawn.h"
#include "./../headers/tir.h"



int main(int argc, char *argv[]){
	srand(time(NULL));

	SDL_Surface *ecran = NULL; // Le pointeur qui va stocker la surface de l'écran
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); // Démarrage de la SDL
	SDL_WM_SetIcon(IMG_Load("sprites/joueur/haut.png"), NULL); // icone programme
	ecran = SDL_SetVideoMode(1260, 728, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); // 1260x728pix , soit 45*26 cases 
	SDL_WM_SetCaption("TankPixel v1", NULL); // Nom programme
	SDL_Event event;
	SDL_EnableKeyRepeat(10, 500);
	//int check = 1;
	int genocide = 0;

	int continuer =0; int difficulte = 0;

	SDL_Surface *imageDeFond = NULL;
	SDL_Rect positionFond;
	positionFond.x = 0;
	positionFond.y = 0;
	imageDeFond = IMG_Load("sprites/animation/menu.png"); 
	SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
	SDL_Flip(ecran);


	char COL[nbLin][nbCol];
	char MAP[nbLin][nbCol];
	char DEST[nbLin][nbCol];
	TITI* titi=NULL;
	TANK* joueur = NULL; OBUS* obus_joueur=NULL;
	TANK* tank1 = NULL;	 OBUS* obus_tank1=NULL;
	TANK* tank2 = NULL;  OBUS* obus_tank2=NULL;
	TANK* tank3 = NULL;  OBUS* obus_tank3=NULL;
	TANK* tank4 = NULL;  OBUS* obus_tank4=NULL;
	TANK* tank5 = NULL;  OBUS* obus_tank5=NULL;
	TANK* tank6 = NULL;  OBUS* obus_tank6=NULL;
	TANK* tank7 = NULL;  OBUS* obus_tank7=NULL;
	TANK* tank8 = NULL;  OBUS* obus_tank8=NULL;
	TANK* tank9 = NULL;  OBUS* obus_tank9=NULL;


	while (continuer==0)   // runMENU
	{
		SDL_Flip(ecran);
		printf("\nMENU\n");

		while(SDL_PollEvent(&event)){
			switch(event.type)
			{

				case SDL_QUIT:
					continuer = 2;
					break;

				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{


						case SDLK_ESCAPE:// Echap 

							continuer = 2;
							break;
						case SDLK_h:

							printf("Lance la game en hard");
							SDL_Flip(ecran);
							LoadMap(MAP,ecran,"carte/hard/map.txt");
							printf("\n"); //  debug
							LoadCol(COL,"carte/hard/collisions.txt");
							LoadDest(DEST,"carte/hard/destruction.txt");
							titi = Spawn_titi(ecran,MAP);
							joueur = Spawn_joueur(ecran,COL);
							tank1 = Spawn_Ennemi(ecran,COL,1);printf("t1");
							tank2 = Spawn_Ennemi(ecran,COL,1);printf("t2");
							tank3 = Spawn_Ennemi(ecran,COL,1);printf("t3");
							tank4 = Spawn_Ennemi(ecran,COL,2);printf("t4");
							tank5 = Spawn_Ennemi(ecran,COL,2);printf("t5");
							tank6 = Spawn_Ennemi(ecran,COL,2);printf("t6");
							tank7 = Spawn_Ennemi(ecran,COL,3);printf("t7");
							tank8 = Spawn_Ennemi(ecran,COL,3);printf("t8");
							tank9 = Spawn_Ennemi(ecran,COL,3);printf("t9");

							obus_tank1 = Init_Obus(ecran,MAP,tank1);printf("1");
							obus_tank2 = Init_Obus(ecran,MAP,tank2);printf("2");
							obus_tank3 = Init_Obus(ecran,MAP,tank3);printf("3");
							obus_tank4 = Init_Obus(ecran,MAP,tank4);printf("4");
							obus_tank5 = Init_Obus(ecran,MAP,tank5);printf("5");
							obus_tank6 = Init_Obus(ecran,MAP,tank6);printf("6");
							obus_tank7 = Init_Obus(ecran,MAP,tank7);printf("7");
							obus_tank8 = Init_Obus(ecran,MAP,tank8);printf("8");
							obus_tank9 = Init_Obus(ecran,MAP,tank9);printf("9");

							continuer = 1;
							difficulte = 2; // on definit la difficulté sur hard
							break;


						case SDLK_e:

							printf("Lance la game en easy");
							SDL_Flip(ecran);
							LoadMap(MAP,ecran,"carte/easy/map.txt");
							printf("\n"); //  debug
							LoadCol(COL,"carte/easy/collisions.txt");
							LoadDest(DEST,"carte/easy/destruction.txt");
							titi = Spawn_titi(ecran,MAP);
							joueur = Spawn_joueur(ecran,COL);
							tank1 = Spawn_Ennemi(ecran,COL,1);printf("t1");
							tank2 = Spawn_Ennemi(ecran,COL,1);printf("t2");
							tank3 = Spawn_Ennemi(ecran,COL,1);printf("t3");

							obus_tank1 = Init_Obus(ecran,MAP,tank1);printf("1");
							obus_tank2 = Init_Obus(ecran,MAP,tank2);printf("2");
							obus_tank3 = Init_Obus(ecran,MAP,tank3);printf("3");

							continuer = 1;
							difficulte = 1; // on definit la difficulté sur easy
							break;



						default:
							break;
					}break;


			}

		}

	}






	while (continuer==1 && titi->vie == 1 && joueur->vie == 1 && genocide ==0)    // rungame
	{
		printf("\nRUNGAME\n");



		SDL_Delay(150);

		if (difficulte == 1){ // si mode facile sélectionné

			if (tank1->vie ==1){
				Controle_ennemi(ecran,COL,MAP,tank1);SDL_Flip(ecran);SDL_Flip(ecran);
				Tir_ennemi(ecran,MAP,tank1,obus_tank1,COL,DEST,joueur,titi);SDL_Flip(ecran);
			}
			if (tank2->vie ==1){
				Controle_ennemi(ecran,COL,MAP,tank2);SDL_Flip(ecran);SDL_Flip(ecran);
				Tir_ennemi(ecran,MAP,tank2,obus_tank2,COL,DEST,joueur,titi);SDL_Flip(ecran);
			}
			if (tank3->vie ==1){
				Controle_ennemi(ecran,COL,MAP,tank3);SDL_Flip(ecran);SDL_Flip(ecran);
				Tir_ennemi(ecran,MAP,tank3,obus_tank3,COL,DEST,joueur,titi);SDL_Flip(ecran);
			}			

			if (tank1->vie == 0 && tank2 ->vie == 0 && tank3->vie == 0){ genocide =1;}

			if (titi->vie ==1){
				Controle_titi(ecran,COL,MAP,titi);SDL_Flip(ecran);SDL_Flip(ecran);

			}	
		}

		if (difficulte == 2){  // si mode difficile selectionné


			if (tank1->vie ==1){
				Controle_ennemi(ecran,COL,MAP,tank1);SDL_Flip(ecran);SDL_Flip(ecran);
				Tir_ennemi(ecran,MAP,tank1,obus_tank1,COL,DEST,joueur,titi);SDL_Flip(ecran);
			}
			if (tank2->vie ==1){
				Controle_ennemi(ecran,COL,MAP,tank2);SDL_Flip(ecran);SDL_Flip(ecran);
				Tir_ennemi(ecran,MAP,tank2,obus_tank2,COL,DEST,joueur,titi);SDL_Flip(ecran);
			}
			if (tank3->vie ==1){
				Controle_ennemi(ecran,COL,MAP,tank3);SDL_Flip(ecran);SDL_Flip(ecran);
				Tir_ennemi(ecran,MAP,tank3,obus_tank3,COL,DEST,joueur,titi);SDL_Flip(ecran);
			}	
			if (tank4->vie ==1){
				Controle_ennemi(ecran,COL,MAP,tank4);SDL_Flip(ecran);SDL_Flip(ecran);
				Tir_ennemi(ecran,MAP,tank4,obus_tank4,COL,DEST,joueur,titi);SDL_Flip(ecran);
			}
			if (tank5->vie ==1){
				Controle_ennemi(ecran,COL,MAP,tank5);SDL_Flip(ecran);SDL_Flip(ecran);
				Tir_ennemi(ecran,MAP,tank5,obus_tank5,COL,DEST,joueur,titi);SDL_Flip(ecran);
			}
			if (tank6->vie ==1){
				Controle_ennemi(ecran,COL,MAP,tank6);SDL_Flip(ecran);SDL_Flip(ecran);
				Tir_ennemi(ecran,MAP,tank6,obus_tank6,COL,DEST,joueur,titi);SDL_Flip(ecran);
			}						

			if (tank7->vie ==1){
				Controle_ennemi(ecran,COL,MAP,tank7);SDL_Flip(ecran);SDL_Flip(ecran);
				Tir_ennemi(ecran,MAP,tank7,obus_tank7,COL,DEST,joueur,titi);SDL_Flip(ecran);
			}
			if (tank8->vie ==1){
				Controle_ennemi(ecran,COL,MAP,tank8);SDL_Flip(ecran);SDL_Flip(ecran);
				Tir_ennemi(ecran,MAP,tank8,obus_tank8,COL,DEST,joueur,titi);SDL_Flip(ecran);
			}
			if (tank9->vie ==1){
				Controle_ennemi(ecran,COL,MAP,tank9);SDL_Flip(ecran);SDL_Flip(ecran);
				Tir_ennemi(ecran,MAP,tank9,obus_tank9,COL,DEST,joueur,titi);SDL_Flip(ecran);
			}	

			if (titi->vie ==1){
				Controle_titi(ecran,COL,MAP,titi);SDL_Flip(ecran);SDL_Flip(ecran);

			}	

			if(tank1->vie == 00 && tank2->vie == 0 && tank3->vie ==0 && tank4->vie ==0 && tank5->vie==0 && tank6->vie == 0 && tank7->vie ==0 && tank8->vie ==0 && tank9->vie==0){genocide=1;}
		}


		while(SDL_PollEvent(&event)){
			switch(event.type)
			{

				case SDL_QUIT:
					//				printf("\nquit\n"); //debug
					continuer = 0;
					difficulte =0;
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{



						case SDLK_UP: // Flèche haut

							Controle_joueur(ecran,COL,MAP,joueur,1);
							break;
						case SDLK_DOWN: // Flèche bas

							Controle_joueur(ecran,COL,MAP,joueur,2);
							break;
						case SDLK_RIGHT: // Flèche droite

							Controle_joueur(ecran,COL,MAP,joueur,3);
							break;
						case SDLK_LEFT: // Flèche gauche

							Controle_joueur(ecran,COL,MAP,joueur,4);

							break;

						case SDLK_z: // Z 
							Controle_joueur(ecran,COL,MAP,joueur,1);
							break;
						case SDLK_s: // S
							Controle_joueur(ecran,COL,MAP,joueur,2);
							break;
						case SDLK_d: // D
							Controle_joueur(ecran,COL,MAP,joueur,3);
							break;
						case SDLK_q: // Q
							Controle_joueur(ecran,COL,MAP,joueur,4);
							break;

						case SDLK_ESCAPE:// Echap 

							continuer = 0;
							difficulte = 0;
							free(joueur);free(obus_joueur);
							free(tank1);free(obus_tank1);
							free(tank2);free(obus_tank2);
							free(tank3);free(obus_tank3);
							free(tank4);free(obus_tank4);
							free(tank5);free(obus_tank5);
							free(tank6);free(obus_tank6);
							free(tank7);free(obus_tank7);
							free(tank8);free(obus_tank8);
							free(tank9);free(obus_tank9);

							break;

						case SDLK_SPACE: // Espace
							printf("Espace");
							obus_joueur = Init_Obus(ecran,MAP,joueur); 
							printf("Tir");
							if(difficulte ==2){
								Tir_hard(ecran,MAP,joueur,obus_joueur,COL,DEST,tank1,tank2,tank3,tank4,tank5,tank6,tank7,tank8,tank9,titi);
							}
							if(difficulte ==1){
								Tir_easy(ecran,MAP,joueur,obus_joueur,COL,DEST,tank1,tank2,tank3,titi);
							}

							break;
						default:
							break;
					}break;


			}
			SDL_Flip(ecran);
		}
	}



	if(continuer == 1){ // si rungame
		while (titi->vie == 0 || joueur->vie == 0){  // si décès de titi ou mort du joueur  => defaite
			printf("\nDEFAITE\n");

			imageDeFond = IMG_Load("sprites/animation/loser.png"); 
			SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
			SDL_Flip(ecran);


			while(SDL_PollEvent(&event)){
				switch(event.type)
				{

					case SDL_KEYDOWN:
						switch(event.key.keysym.sym)
						{

							case SDLK_RETURN:
								titi->vie = 1;
								joueur->vie = 1;
								free(joueur);free(obus_joueur);
								free(tank1);free(obus_tank1);
								free(tank2);free(obus_tank2);
								free(tank3);free(obus_tank3);
								free(tank4);free(obus_tank4);
								free(tank5);free(obus_tank5);
								free(tank6);free(obus_tank6);
								free(tank7);free(obus_tank7);
								free(tank8);free(obus_tank8);
								free(tank9);free(obus_tank9);
								break;


							default:
								break;
						}break;


				}

			}


		}
	}

	while (genocide){  // si décès de tout les ennemis  => victoire
		printf("\nVICTOIRE\n");

		imageDeFond = IMG_Load("sprites/animation/winner.png"); 
		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
		SDL_Flip(ecran);


		while(SDL_PollEvent(&event)){
			switch(event.type)
			{

				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{

						case SDLK_RETURN:
							titi->vie = 1;
							joueur->vie = 1;
							genocide =0;
							free(joueur);free(obus_joueur);
							free(tank1);free(obus_tank1);
							free(tank2);free(obus_tank2);
							free(tank3);free(obus_tank3);
							free(tank4);free(obus_tank4);
							free(tank5);free(obus_tank5);
							free(tank6);free(obus_tank6);
							free(tank7);free(obus_tank7);
							free(tank8);free(obus_tank8);
							free(tank9);free(obus_tank9);
							break;


						default:
							break;
					}break;


			}

		}


	}

	SDL_Quit();
	return EXIT_SUCCESS;


}
