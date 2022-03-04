#ifndef XMALLOC_H
#define XMALLOC_H

void
*xmalloc(size_t size, void(handle)());

void
*xcalloc(size_t nmemb, size_t size, void(handle)());

void
*xrealloc(void *ptr, size_t size, void(handle)());

#endif /* XMALLOC_H */
