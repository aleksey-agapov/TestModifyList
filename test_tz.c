


// #include <stdio.h>
#include <assert.h>
// #include <stdlib.h>  // malloc
#include <string.h>  // memset
#include "test_tz.h"


const ssize_t record_size = sizeof(list_t); /* Size of list structure*/

	/* Counts the number of items in a list.
	*/
int count_list_items(const list_t *head) {
	if (head) {
		if (head->next) {
			return count_list_items(head->next) + 1;
		} else {
			return 1;
		}
	} else {
		return 0;
	}
}

	/* Inserts a new list item after the one specified as the argument.
	*/
list_t * insert_next_to_list(list_t *item, int data) {
//	ssize_t record_size = sizeof(list_t);
	list_t * ret_item = malloc(record_size);
	if (!ret_item) {assert((!ret_item)&&"ERROR GET MEMORY FROM NEW_LIST_ITEM!");}
	memset(ret_item, 0, record_size);
	ret_item->data = data;
	if (item) {   /* if is not first  */
		ret_item->before = item;
		ret_item->next = item->next;
		item->next = ret_item;
	}
	return ret_item;
}


	/* Removes select item as the argument.
	*/
int remove_current_from_list(list_t *item) {
	int ret_code = -1;
	if (item) {
		if (item->next) {
			item->next->before = item->before;
		}
		if (item->before) {
			item->before->next = item->next;
		}
		free(item);
		ret_code = 0;
	}
	return ret_code;
}


	/* Removes an item following the one specificed as the argument.
	*/
int remove_next_from_list(list_t *item) {
	int ret_code = -1;
	if (item) {
		ret_code = remove_current_from_list(item->next) ;
	}
	return ret_code;
}

	/* Returns item data as text.
	 */
char *item_data(const list_t *list)
{
	int size_buff = 0;
	char * ret_str = NULL;
	if (list) {
		if(list->data) {
			int counter = abs(list->data);
			if (counter != list->data) {size_buff++;} /* is list->data < 0 */

			while (counter) {
				counter/=10;
				size_buff++;
			}
		} else {
			size_buff = 1;
		}
		ret_str = malloc(++size_buff);
		if (!ret_str) {assert((!ret_str)&&"ERROR GET MEMORY FROM RET_STRING_BUFFER!");}
		memset(ret_str, 0, size_buff);
		sprintf(ret_str,"%d",list->data); /* converts to decimal base. */
	}
	return ret_str;
}



