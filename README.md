# Задание от Auriga
```
1) The following code compiles on Linux. It has a number of problems, however. Please locate as many of those problems as you are able and provide your recommendations regarding how they can be resolved.

typedef struct list_s
{
        struct list_s *next; /* NULL for the last item in a list */
        int data;
}
list_t;

	/* Counts the number of items in a list.
	 */
int count_list_items(const list_t *head) {
	if (head->next) {
		return count_list_items(head->next) + 1;
	} else {
		return 1;
	}
}

    /* Inserts a new list item after the one specified as the argument.
	 */
void insert_next_to_list(list_t *item, int data) {
	(item->next = malloc(sizeof(list_t)))->next = item->next;
	item->next->data = data;
}

    /* Removes an item following the one specificed as the argument.
	 */
void remove_next_from_list(list_t *item) {
	 if (item->next) {
		free(item->next);
        item->next = item->next->next;
     }
}

	/* Returns item data as text.
	 */
char *item_data(const list_t *list)
{
	char buf[12];

	sprintf(buf, "%d", list->data);
	return buf;
}
```



# Комментарий технического специалиста: 
По списку никаких изменений не предложил. В качестве решения дал ссылку на репозиторий, где выложил тесты для нашей библиотеки. Написал мэйкфайл. Чтобы собиралось, объявил прототипы наших функций как extern. Как это все должно работать, все равно не понятно, поскольку собственно реализации наших функций в репозитории не нашел. Что он этим хотел сказать не понятно. 