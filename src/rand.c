#include <stdio.h>
#include <stdlib.h>

#include <qlib/rand.h>

unsigned int
get_rand_uint()
{
	FILE *fp = fopen("/dev/urandom","r");
	unsigned int num;
	fread(&num,sizeof(int),1,fp);

	return num;
}

#ifdef testing

int
main(void)
{
	printf("%u\n",(unsigned)get_rand_number());
	return 0;
}
#endif  /* testing */
