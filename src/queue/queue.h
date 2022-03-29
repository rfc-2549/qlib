#include <stdio.h>

#define LIST_ENTRY(entry)                                                      \
	struct                                                                    \
	{                                                                         \
		struct entry *next;                                                  \
		struct entry *prev;                                                  \
	}
#define LIST_HEAD(name, type)                                                  \
	struct name                                                               \
	{                                                                         \
		struct type *l_head;                                                 \
	}

#define LIST_INIT(head) (head)->l_head = NULL

#define LIST_INSERT_HEAD(head, elem, entry)                                    \
	(elem)->entry.next = NULL;                                                \
	if((head)->l_head == NULL) {                                              \
		(head)->l_head = elem;                                               \
	} else {                                                                  \
		entry *old_head = (head)->l_head;                                    \
		(head)->l_head = elem;                                               \
		(elem)->entry.next = old_head;                                       \
	}
#define LIST_POP(head, entry)                                                  \
	if((head)->l_head != NULL)                                                \
	(head)->l_head = (head)->l_head->entry.next
