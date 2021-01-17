#include <stdio.h>
#include "Book.h"

extern Book* start;
extern int value;
void add_number(void)
{
	Book *cur = NULL;
	Book* new_num = NULL;
	int id;

	if (start == NULL)
	{
		new_num = (Book*)malloc(sizeof(Book));
		scanf("%s %s %d\n", new_num->name, new_num->tel, new_num->birth);
		new_num->next = NULL;
		new_num->id = value++;
		start = new_num;
	}
	/*else
	{
		new_num = (Book*)malloc(sizeof(Book));
		new_num->next = NULL;
		new_num->id = value++;
		
		for (cur = start; cur->next != NULL; cur = cur->next);
		insert_end(cur, new_num);
	}*/
}

/*void insert_end(Book* end, Book* new_num)
{
	end->next = new_node;
}*/