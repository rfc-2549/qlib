/* Array shuffler */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void
shuffle(void *base, size_t len, size_t nmemb)
{
	char *tmp[len];
	char *arr = base;
	int stride = nmemb * sizeof(char);

	if(len > 1) {
		for(size_t i = 0; i < len - 1; i++) {
			int j = i + rand() / (RAND_MAX / (len - i) + 1);
			memcpy(tmp, arr + j * stride, nmemb);
			memcpy(arr + j * stride, arr + i * stride, nmemb);
			memcpy(arr + i * stride, tmp, nmemb);
		}
	}
	// free(tmp);
}

#ifdef testing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int
main(void) {
	srand(time(0));
	int x[5] = {1,2,3,4,5};
	shuffle(x,5,sizeof(int));
	for(int i = 0; i < 5; i++) {
		printf("%i\n",x[i]);
	}
	return 0;
}
#endif  /* testing */
