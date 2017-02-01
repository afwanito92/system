#include <stdio.h>
#define BUFFER 200
void create(){
	FILE *fp;
	fp =fopen("toto", "w+");
	fputs("Ceci est un test \n C'est marrant", fp);	
	fclose(fp);
}
//on veut copier le texte de toto et l'envoyer dans titi
int main(int argc, char **argv)
{
	//declaration des variables
	FILE *f;
	FILE *g;
	int c;
	char car[BUFFER] = "";
	//on ouvre les fichiers titi et toto
	f = fopen("toto", "r");
	g = fopen("titi", "w");
	
	//Si f est null on créé un fichier toto 
	if (f == NULL){
		create();
	}
	//ensuite on lit ligne par ligne 
	while (fgets(car, BUFFER, f) != NULL){
		fputs(car, g);
	}
	fclose(f);
	fclose(g);
	return 0;
}

