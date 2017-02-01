#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int faux (char * nom){
	int fp;
	int c;
	size_t rd;
	fp = open(nom, O_RDWR);
	rd = read (fp, &c, 1);
	close(fp);
	return c;
}
int main(int argc, char **argv)
{
    faux("test");
	return 0;
}

