#pragma once
struct Phonebook
{
	struct Phonebook* next;
	int id;	
	char name[20];
	char tel[20];
	int birth;
};

typedef struct Phonebook Book;
