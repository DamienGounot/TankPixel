#include <stdio.h>
#include <stdlib.h>


void GENERATEUR_DE_MAP( char* nom_carte,char* nom_collisions, char* nom_destruction){
	FILE* carte=NULL;
	FILE* collisions=NULL;
    FILE* destruction=NULL;

    char caract;

	carte = fopen(nom_carte, "r");
	collisions = fopen(nom_collisions,"a");
	destruction = fopen(nom_destruction,"a");

	while((caract=fgetc(carte))!=EOF){ // Tant que le caract != EOF

		if(caract >= 'A' && caract <= 'Z'){ // Si le caract est entre A et Z

            switch(caract){

                    case 'H':  //Herbe
                        fputc('F',collisions); // franchissable
                        fputc('D',destruction);  // destructible

                    break;
                    case 'E': // Eau
                    fputc('I',destruction);  // indestructible
                    fputc('C',collisions); // collision
                    break;
                    case 'A':  // Arbre
                    fputc('C',collisions);  // collision
                    fputc('D',destruction);  // destructible
                    break;
                    case 'P':  // Pont
                    fputc('I',destruction);  // indestructible
                    fputc('F',collisions); // franchissable
                    break;
                    case 'M':  // Mur
                    fputc('C',collisions);  // collision
                    fputc('D',destruction);  // destructible                    
                    break;

            }

			
            

		}
	}

	fclose(carte);
	fclose(collisions);
    fclose(destruction);
}

/////////////////////////
/////////////////////////

int main(int argc, char *argv[]){

	GENERATEUR_DE_MAP(argv[1],argv[2],argv[3]); // MAP COL DEST

	return 0;

}

