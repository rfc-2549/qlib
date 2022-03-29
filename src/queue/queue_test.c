#include <stdio.h>
#include <qlib/tui.h>
#include <qlib/colors.h>
#include <stdlib.h>

#include "queue.h"

typedef struct list_entry
{
	float value;
	LIST_ENTRY(list_entry) list_entry;
} list_entry;

LIST_HEAD(head_struct, list_entry) head;

int
main(void)
{
	struct list_entry s1;
	s1.value = 3.14;
	struct list_entry s2;
	s2.value = 1.41;
	struct list_entry s3;
	s3.value = 5.14;
	struct list_entry s4;
	s4.value = 7.14;
	struct list_entry s5;
	s5.value = 54;

	struct list_entry *np;

	LIST_INIT(&head);

	LIST_INSERT_HEAD(&head, &s1, list_entry);
	LIST_INSERT_HEAD(&head, &s2, list_entry);
	LIST_INSERT_HEAD(&head, &s3, list_entry);
	LIST_INSERT_HEAD(&head, &s4, list_entry);
	LIST_INSERT_HEAD(&head, &s5, list_entry);

	for(np = head.l_head; np != NULL; np = np->list_entry.next) {
		printf("Value: %f\n", np->value);
		printf("Address: %p\n", np->list_entry.next);
	}

	LIST_POP(&head, list_entry);
	LIST_POP(&head, list_entry);

	puts("---------------");
	for(np = head.l_head; np != NULL; np = np->list_entry.next) {
		printf("Value: %f\n", np->value);
		printf("Address: %p\n", np->list_entry.next);
	}
	return 0;
}
