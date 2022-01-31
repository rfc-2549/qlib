/* Allocators that handle errors */
#include <stdlib.h>

void
*xmalloc(size_t size, void(handle)())
{
	void *ptr = malloc(size);
	if(ptr == NULL) {
		handle();
		return NULL;
	} else
		return ptr;
}

void
*xcalloc(size_t nmemb, size_t size, void(handle)())
{
	void *ptr = calloc(nmemb, size);
	if(ptr == NULL) {
		handle();
		return NULL;
	} else
		return ptr;
}

void
*xrealloc(void *ptr, size_t size, void(handle)())
{
	void *ptr_r = realloc(ptr,size);
	if(ptr_r == NULL) {
		handle();
		return NULL;
	} else
		return ptr_r;
}


#ifdef testing
void*malloc(size_t t) {return NULL;}
void*calloc(size_t t,size_t n) {return NULL;}
void*realloc(void *ptr, size_t t) {return NULL;}

void handle() {puts("I'm handling!");}

int
main(void)
{
	xmalloc(1,handle);
	xcalloc(1,2,handle);
	xrealloc(NULL,2,handle);
}
#endif
