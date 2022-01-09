#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "nutility.h"
#include "personlist.h"
#include "person.h"


int main()
{
	Person per;

	randomize();
	ListHandle h1 = create_list();
	for (int i = 0; i < 10; ++i) {
		set_random_person(&per);
		push_front(h1, &per);
	}

	ListHandle h2 = create_list();
	for (int i = 0; i < 20; ++i) {
		set_random_person(&per);
		push_front(h2, &per);
	}

	ListHandle h3 = create_list();
	for (int i = 0; i < 15; ++i) {
		set_random_person(&per);
		push_front(h3, &per);
	}

	printf("1. listede %d kisi var\n", get_size(h1));
	printf("2. listede %d kisi var\n", get_size(h2));
	printf("3. listede %d kisi var\n", get_size(h3));

	printf("1.liste\n");
	print_list(h1);
	_getch();
	system("cls");

	printf("2.liste\n");
	print_list(h2);
	_getch();
	system("cls");

	printf("3.liste\n");
	print_list(h3);
	_getch();
	system("cls");

	destroy_list(h1);
	destroy_list(h2);
	destroy_list(h3);

}