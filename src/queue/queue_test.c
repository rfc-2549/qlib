#include <stdio.h>
#include <qlib/tui.h>
#include <qlib/colors.h>
#include <stdlib.h>
#include <stdint.h>

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

	/* Breaking ankles, necks and backs
	 * Then the circle begins
	 * In the thrashing pit
	 *  Fist are flying
	 * People getting hit
	 *  Tooth chippers left and right
	 *  Skinheads in another fight
	 *  Banging heads and broken jaws
	 *  Because there are no laws
	 *
	 *  In the heap.
	 */
	struct list_entry *s1, *s2, *s3, *s4, *s5;
	struct list_entry *np;

	s1 = malloc(sizeof(list_entry));
	s1->value = 3.14;
	s2 = malloc(sizeof(list_entry));
	s2->value = 2.78;
	s3 = malloc(sizeof(list_entry));
	s3->value = 1.1;
	s4 = malloc(sizeof(list_entry));
	s4->value = 10.1;
	s5 = malloc(sizeof(list_entry));
	s5->value = 3123.23;

	LIST_INIT(&head);

	LIST_INSERT_HEAD(&head, s1, list_entry);
	LIST_INSERT_HEAD(&head, s2, list_entry);
	LIST_INSERT_HEAD(&head, s3, list_entry);
	LIST_INSERT_HEAD(&head, s4, list_entry);
	LIST_INSERT_TAIL(&head, s5, list_entry);

	for(np = head.l_head; np != NULL; np = np->list_entry.next) {
		printf("Value: %f\n", np->value);
		np->list_entry.next == NULL
			? puts("Last element")
			: printf("Address: 0x%lX\n", (intptr_t)np->list_entry.next);
	}
	/* Free the thing before popping */
	LIST_POP(&head, list_entry);
	free(s4);
	LIST_POP(&head, list_entry);
	free(s3);
	puts("---------------");
	
	for(np = head.l_head; np != NULL; np = np->list_entry.next) {
		printf("Value: %f\n", np->value);
		np->list_entry.next == NULL
			? puts("Last element")
			: printf("Address: 0x%lX\n", (intptr_t)np->list_entry.next);
	}

	/* From here, valgrind complains. And that's unacceptable. */

	while(head.l_head != NULL) {
		list_entry *tmp = head.l_head;
		head.l_head = head.l_head->list_entry.next;
		free(tmp);
	}

	return 0;
}
