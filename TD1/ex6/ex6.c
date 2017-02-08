#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
// ls -l :
// on a une commande qui affiche la totalite des infos sur un fichier
// on obtient pour chaque objets trouves :
// [type (d si dossier sinon -)] [droits pour : user] [group] [other] [numero] [nom ut] [nom gpe] [date de derniere modif] [nom de fichier]
//dans les droits r : lecture, w ecriture, x execution
// ICI le but est de faire un programme, qui affiche les droits, et le nom du fichier

// Macro : fonction precompilee
int main(int argc, char **argv)
{
	//on regarde si on a des arguments apres la commande de lancement
	if (argc != 2){
    return 1;
  }
  //si oui on continue
  //on cree un struct stat
	struct stat fstat;

  //on regarde si on peut s'en servir
  //la fonction stat a le prototype suivant
  // int stat (const char * path, struct stat * buf)

  // si il y a une erreur on quittei
  if (stat(argv[1], &fstat) < 0){
    perror("stat");
    return 1;i

  }
i
  //sinon c'est gagne on affiche
  //regarde si c'est un dossier
  printf( (S_ISDIR(fstat.st_mode) ) ? "d" : "-");
  //on regarde les permissions utilisateur
  //quand on a xxx & yyy on a la verification du masque yyy sur xxx
  //ex if (attr.st_mode &(S_IRUSR | S_IWUSR)) --> on verifie deux masque sur st_mode en même temps
  
  printf( (fstat.st_mode & S_IRUSR) ? "r" : "-");
  printf( (fstat.st_mode & S_IWUSR) ? "w" : "-");
  printf( (fstat.st_mode & S_IXUSR) ? "x" : "-");

  //puis celles du groupe

  printf( (fstat.st_mode & S_IRGRP) ? "r" : "-");
  printf( (fstat.st_mode & S_IWGRP) ? "w" : "-");
  printf( (fstat.st_mode & S_IXGRP) ? "x" : "-");

  //puis celle des autres utilisateurs

  printf( (fstat.st_mode & S_IROTH) ? "r" : "-");
  printf( (fstat.st_mode & S_IWOTH) ? "w" : "-");
  printf( (fstat.st_mode & S_IXOTH) ? "x" : "-");
  //espace
  printf(" ");
  //nom du fichier
  printf("%s \n", argv[1]);
	return 0;
}
