/*
 * test_tz.h
 *
 *  Created on: Nov 19, 2020
 *      Author: Agapov Aleksey
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>  // malloc
#include <stdio.h>   // sprintf printf


typedef struct list_s
{
        struct list_s *before; /* NULL for the first item in a list */
        struct list_s *next; /* NULL for the last item in a list */
        int data;
}
list_t;

extern int count_list_items(const list_t *head);
extern list_t * insert_next_to_list(list_t *item, int data);
extern int remove_current_from_list(list_t *item);
extern int remove_next_from_list(list_t *item);
extern char *item_data(const list_t *list);
#endif /* LIST_H_ */
