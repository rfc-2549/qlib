#ifndef RAND_H
#define RAND_H
#include <stdint.h>
#include <stdlib.h>

unsigned int
get_rand_uint();	

void
get_rand(void *ptr, size_t size);

int8_t
get_rand_int8();

int16_t
get_rand_int16();

int32_t
get_rand_int32();

int64_t
get_rand_int64();

#ifdef __GNUC__
__int128_t
get_rand_int128();
#endif  /* __GNUC__ */

#endif /* RAND_H */
