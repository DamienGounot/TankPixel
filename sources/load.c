
#include "./../headers/load.h"



void LoadMap( char MAP[nbLin][nbCol],SDL_Surface *ecran,char* nom_map){



	/* Importation matrice de la map */

	FILE* carte = NULL;
	carte = fopen(nom_map, "r"); // ouverture du fichier en lecture
	if (carte == NULL){printf("Pas de map");exit(-1);} // detection erreur ouverture

	char carre; // case du plateau
	int i,j;

	printf("\n    012345678901234567890123456789012345678901234\n\n"); // debug

	for(i=0;i<nbLin;i++){

		printf("%d : ",i%10); //debug

		for(j=0;j<nbCol;j++){

			carre=fgetc(carte); // on recup la carte dans le txt
			if(carre >= 'A' && carre <= 'Z'){ //si lettre

				MAP[i][j] = carre; // on charge la carte sur la map

			}
			printf("%c",MAP[i][j]); // affichage pour debug

		}
		printf("\n"); //debug
	}

	fclose(carte);


	/*affichage map en fonction de la matrice */


	SDL_Surface *case_plateau = NULL;
	SDL_Rect position_case_plateau; 


	for(i=0;i<nbLin;i++){


		for(j=0;j<nbCol;j++){

			//			printf("i :%d  j: \n%d",i,j); // pour debug

			position_case_plateau.x=j*28;
			position_case_plateau.y=i*28;

			if(MAP[i][j] == 'H') { 
				case_plateau = IMG_Load("sprites/sol/herbe.png");
				SDL_BlitSurface(case_plateau, NULL, ecran, &position_case_plateau);

			}

			if(MAP[i][j] == 'E') { 
				case_plateau = IMG_Load("sprites/sol/eau.png");
				SDL_BlitSurface(case_plateau, NULL, ecran, &position_case_plateau);

			}


			if(MAP[i][j] == 'M') { 
				case_plateau = IMG_Load("sprites/obstacle/mur.png");
				SDL_BlitSurface(case_plateau, NULL, ecran, &position_case_plateau);

			}

			if(MAP[i][j] == 'A') { 
				case_plateau = IMG_Load("sprites/sol/herbe.png");
				SDL_BlitSurface(case_plateau, NULL, ecran, &position_case_plateau);
				free(case_plateau);
				case_plateau = IMG_Load("sprites/sol/arbre.png");
				SDL_BlitSurface(case_plateau, NULL, ecran, &position_case_plateau);

			}

			if(MAP[i][j] == 'P') { 
				case_plateau = IMG_Load("sprites/sol/pont.png");
				SDL_BlitSurface(case_plateau, NULL, ecran, &position_case_plateau);

			}

		/*	if(MAP[i][j] == 'T') { 
				case_plateau = IMG_Load("sprites/sol/herbe.png");
				case_plateau = IMG_Load("sprites/obstacle/titi.png");
				SDL_BlitSurface(case_plateau, NULL, ecran, &position_case_plateau);
		
			}
		*/

		}
	}

	SDL_Flip(ecran);

}



void LoadCol(char COL[nbLin][nbCol],char* nom_col){
	/* Importation matrice de collision */

	FILE* collision = NULL;
	collision = fopen(nom_col, "r"); // ouverture du fichier en lecture
	if (collision == NULL){printf("\nPas de collisions");exit(-1);} // detection erreur ouverture

	char col; // case du plateau
	int i,j;
	printf("\n    012345678901234567890123456789012345678901234\n\n"); // debug
	for(i=0;i<nbLin;i++){
		printf("%d : ",i%10); //debug
		for(j=0;j<nbCol;j++){

			col=fgetc(collision); // on recup la col dans le txt
			if(col == 'C'){ //si col

				COL[i][j] = col; // on charge les col dans la matrice

			}else{
				COL[i][j] = 'F';
			}
			printf("%c",COL[i][j]); // affichage pour debug

		}
		printf("\n"); //debug
	}

	fclose(collision);
}


void LoadDest(char DES[nbLin][nbCol],char* nom_dest){

	/* Importation matrice de destruction */

	FILE* destruction = NULL;
	destruction = fopen(nom_dest, "r"); // ouverture du fichier en lecture
	if (destruction == NULL){printf("\nPas de destruction");exit(-1);} // detection erreur ouverture

	char des; // case du plateau
	int i,j;
	printf("\n    012345678901234567890123456789012345678901234\n\n"); // debug
	for(i=0;i<nbLin;i++){
		printf("%d : ",i%10); //debug
		for(j=0;j<nbCol;j++){

			des=fgetc(destruction); // on recup la destrutibilité dans le txt
			if(des == 'D'){ //si destructible

				DES[i][j] = des; // on charge la destrutibilité dans la matrice

			}else{
				DES[i][j] = 'I';
			}
			printf("%c",DES[i][j]); // affichage pour debug

		}
		printf("\n"); //debug
	}

	fclose(destruction);
}
