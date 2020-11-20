/*
 ============================================================================
 Name        : test_c.c
 Author      : Agapov Aleksey
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#include "test_tz.h"


int main(void) {
	puts("!!!========================================================!!!"); /*  */

	list_t * root = insert_next_to_list(NULL,0);
	list_t * next = root;
	list_t * last = root;
	for (int count=2000000000;count<2000000035;count++) {
		next = insert_next_to_list(next,count);
		last = next;
	}

	next = root;
	int count =0;
	while (next) {
		char * list_data = item_data(next);
		printf ("item:%d\t->%s\n",count++, list_data);
		free(list_data);
		next = next->next;
	}

	next = last->before;
	while (next) {
		last = next;
		char * list_data = item_data(next->next);
		printf ("remove_next_from_list->%s retcode:%d\n",list_data, remove_next_from_list(next));
		free(list_data);
		next = next->before;
	}

	printf ("remove_root_item->%s retcode:%d\n",item_data(root), remove_current_from_list(root));

	return EXIT_SUCCESS;
}
