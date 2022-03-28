#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef ENABLE_GC
#include <gc/gc.h>
#endif

/* Concatenates 2 strings, automatically malloc()in' the result
 * string. The return value should be free()'d.*/

char *
q_strcat(const char *s1, const char *s2)
{
	int size_1 = strlen(s1);
	int size_2 = strlen(s2);
	int size_new = size_1 + size_2;
#ifdef ENABLE_GC
	char *return_string = GC_malloc(size_new);
	#else
	char *return_string = malloc(size_new);
#endif
	int x = 0;

	for(int i = 0; i < size_new; i++) {
		if(i < size_1) { /* Finished copying first string */
			return_string[i] = s1[i];
		} else {
			return_string[i] = s2[x];
			x++;
		}
	}
	return_string[size_new] = 0;

	return return_string;
}

int
main(void)
{

	char *x = "Hello ";
	char *y = "World";

	char *z = q_strcat(x, y);
	puts(z);
	free(z);

	return 0;
}
