#include <stdio.h>
#include <stdlib.h>


void CHIFF_CESAR(int k, char* nom_fic_clair,char* nom_fic_chiff){
	char caract;
	FILE* fichier_clair=NULL;
	FILE* fichier_chiff=NULL;

	fichier_clair = fopen(nom_fic_clair, "r");
	fichier_chiff = fopen(nom_fic_chiff,"w");

	if (fichier_clair == NULL){printf("Pas de fichier clair");exit(-1);}
	if (fichier_chiff == NULL){printf("Pas de fichier chiff");exit(-1);}

	while((caract=fgetc(fichier_clair))!=EOF){ // Tant que le caract != EOF

		if(caract >= 'A' && caract <= 'Z'){ // Si le caract est entre A et Z

			fputc(((caract-'A'+k)%26)+'A',fichier_chiff);

		}else if (caract >= 'a' && caract <= 'z'){ // si le caract est entre a et z

			fputc(((caract-'a'+k)%26)+'a',fichier_chiff);

		}

//	printf("%c",caract);
	}

	fclose(fichier_clair);
	fclose(fichier_chiff);
}

/////////////////////////

void DECHIFF_CESAR(int k,char* nom_fic_chiff,char* nom_fic_dechiff){ 
	char caract;
	FILE* fichier_chiff=NULL;
	FILE* fichier_dechiff=NULL;

	fichier_chiff = fopen(nom_fic_chiff, "r");
	fichier_dechiff = fopen(nom_fic_dechiff,"w");

	if (fichier_chiff == NULL){printf("Pas de fichier chiff");exit(-1);}
	if (fichier_dechiff == NULL){printf("Pas de fichier dechiff");exit(-1);}

	while((caract=fgetc(fichier_chiff))!=EOF){ // Tant que le caract != EOF

		if(caract >= 'A' && caract <= 'Z'){ // Si le caract chiffré est entre A et Z

			fputc(((caract-'A'-k+26)%26)+'A',fichier_dechiff);

		}else if (caract >= 'a' && caract <= 'z'){ // si le caract chiffré est entre a et z

			fputc(((caract-'a'-k+26)%26)+'a',fichier_dechiff);
		}

//		printf("%c",caract);
	}

	fclose(fichier_chiff);
	fclose(fichier_dechiff);
}
/////////////////////////

int main(int argc, char *argv[]){

int k=0;
printf("Decallage de cb ?\n");
scanf("%d",&k);

	CHIFF_CESAR(k,argv[1],argv[2]);
	DECHIFF_CESAR(k,argv[2],argv[3]);

	return 0;

}

