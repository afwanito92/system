#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
//on cherche a ouvrir et lire dans un fichier
//methode open
//fopen dans l'ex2BIS.c

int faux (char * nom){
	int fp;
	int c;
	size_t rd;
	fp = open(nom, O_RDONLY);
	rd = read (fp, &c, 1);
	close(fp);
	return c;
}
int main(int argc, char **argv)
{
    faux("test");
	return 0;
}

