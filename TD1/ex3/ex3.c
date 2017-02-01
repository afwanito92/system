#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define BUFFER 200
void create(){
	int fp;
	int c = 65;
	fp = open("toto", O_RDONLY | O_CREAT, S_IRWXU);
	write(fp, &c, sizeof(char));	
	close(fp);
}
//on veut copier le texte de toto et l'envoyer dans titi
int main(int argc, char **argv)
{
	//declaration des variables
	int f;
	int g;
	int c;
	
	//on ouvre les fichiers titi et toto
	f = open("toto", O_RDONLY);
	
	//on prepare g de sorte a ce qu'on puisse creer un fichier
	g = open("titi", O_CREAT | O_WRONLY, S_IRWXU);
	
	//Tant que f = -1  on créé un fichier toto 
	while (f == -1){
		close(f);
		create();
		f = open("toto", O_RDONLY);
	
	}
	
	//ensuite on lit ligne par ligne 
	
	while (read(f, &c, sizeof(char))){
		write(g, &c, sizeof(char));
	}
	printf("a");
	close(f);
	close(g);
	return 0;
}

