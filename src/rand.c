#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// #include <qlib/rand.h>

void
get_rand(void *ptr, size_t size)
{
	FILE *fp = fopen("/dev/urandom", "r");
	fread(ptr, size, 1, fp);
	fclose(fp);
}

int8_t
get_rand_int8()
{
	int16_t num;
	get_rand(&num, sizeof(int8_t));
	return num;
}

int16_t
get_rand_int16()
{
	int16_t num;
	get_rand(&num, sizeof(int16_t));
	return num;
}

int32_t
get_rand_int32()
{
	int32_t num;
	get_rand(&num, sizeof(int32_t));
	return num;
}

int64_t
get_rand_int64()
{
	int64_t num;
	get_rand(&num, sizeof(int64_t));
	return num;
}
/* Please don't use this. */

#ifdef __GNUC__
__int128_t
get_rand_int128()
{
	__int128_t num;
	get_rand(&num, sizeof(__int32_t));
	return num;
}

#endif /* __GNUC__ */

#ifdef testing

int
main(void)
{
	int64_t *ptr = malloc(10 * sizeof(int64_t));

	for(int i = 0; i < 10; i++)
		ptr[i] = get_rand_int64() % 50;
	for(int i = 0; i < 10; i++)
		printf("%ld\n",ptr[i]);
	free(ptr);
	
	return 0;
}
#endif /* testing */
