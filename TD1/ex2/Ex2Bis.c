#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

//on cherche a lire dans un fichier 
// méthode fopen 
//pour open voir l'ex2.c
int faux (char * nom){
	FILE *fp;
	int c;
	fp = fopen(nom, "r");
	fread (&c, 1, sizeof(int), fp);
	fclose(fp);
	return c;
}
int main(int argc, char **argv)
{
    faux("test");
	return 0;
}

