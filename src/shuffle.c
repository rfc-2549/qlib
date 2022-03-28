/* Array shuffler,*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

#include "../inc/qlib/shuffle.h"
#include "../inc/qlib/rand.h"

void
shuffle(void *base, size_t len, size_t nmemb)
{
	char *tmp = malloc(len * nmemb);
	char *arr = base;
	int stride = nmemb * sizeof(char);

	if(len > 1) {
		for(size_t i = 0; i < len - 1; i++) {
			uint32_t x = (unsigned)get_rand_int32();
			uint32_t j = i + x / (RAND_MAX / (len - i) + 1);
			/* Sometimes j can be larger than the length, in this
			 * case decrement the thing until it's a valid array index.
			 */
			while(len - 1 < j)
				j--;
			memcpy(tmp, arr + j * stride, nmemb);
			memcpy(arr + j * stride, arr + i * stride, nmemb);
			memcpy(arr + i * stride, tmp, nmemb);
		}
	}
	free(tmp);
}

#ifdef testing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int
main(void)
{
	srand(time(NULL));
	int x[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	shuffle(x, 8, sizeof(int));
	for(int i = 0; i < 8; i++) {
		printf("%i\n", x[i]);
	}
	return 0;
}
#endif /* testing */
