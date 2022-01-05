/*
	- Welcome to the program!.
	- The program was designed to save information about books,
	- such as its owner, publication date and house, its topic etc.
	- Every single book will have its own .text file that contains these informations.
	- I hope you find that useful.
	- That program was created using C language with Microsoft Visual Studio 2017.

*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>



struct library {

	char title[50];
	char tutor[20];
	char subject[100];
	int PageNumber;
	char PublicationDate[8];
	char PublicationHouse[100];

};

int main() {

	printf("%s", "Welcome to the Library with C\n\n");
	printf("%s", "That program creates .text files,\n");
	printf("%s", "that contains its owner of book, publication date, number of pages,\n");
	printf("%s", "for every single book entered to program.\n\n");

choose: printf("%s", "Do you wish to add a new book to library, or search for?\nPlease choose below according to your wishes:\n");
	printf("%s", "1- Add a new book\n");
	printf("%s", "2- Search a book\n");


	int user_choice = 0;
	scanf_s("%d", &user_choice);

	struct library book;

	char BookName[50];
	char BookWriter[20];
	char BookTopic[100];
	char BookPublicationDate[9];
	char BookPublicationHouse[100];
	int BookPageNumber;

	char Storage[] = "TotalAmountOfBook";

	if (user_choice == 1) {

		printf("%s", "Please, enter the following information about the book to save it.\n");

		printf("%s", "Book Name: ");
		scanf_s("%49s", BookName, (unsigned)_countof(BookName));

		printf("%s", "Tutor Name: ");
		scanf_s("%19s", BookWriter, (unsigned)_countof(BookWriter));

		printf("%s", "Subject: ");
		scanf_s("%99s", BookTopic, (unsigned)_countof(BookTopic));

		printf("%s", "Book Page: ");
		scanf_s("%d", &BookPageNumber);

		printf("%s", "Book' Publication Date: ");
		scanf_s("%8s", BookPublicationDate, (unsigned)_countof(BookPublicationDate));

		printf("%s", "Book' Publication House: ");
		scanf_s("%99s", BookPublicationHouse, (unsigned)_countof(BookPublicationHouse));

		strcpy_s(book.title, sizeof book.title, BookName);
		strcpy_s(book.tutor, sizeof book.tutor, BookWriter);
		strcpy_s(book.subject, sizeof book.subject, BookTopic);
		book.PageNumber = BookPageNumber;
		strcpy_s(book.PublicationDate, sizeof book.PublicationDate, BookPublicationDate);
		strcpy_s(book.PublicationHouse, sizeof book.PublicationHouse, BookPublicationHouse);

		FILE *AddBook;
		fopen_s(&AddBook, book.title, "w+");
		fprintf(AddBook, "%s %s %d %s %s", &book.tutor[0], &book.subject[0], book.PageNumber, &book.PublicationDate[0], &book.PublicationHouse[0]);
		fclose(AddBook);

		FILE *SaveBook;
		fopen_s(&SaveBook, Storage, "a");
		fprintf_s(SaveBook, "*");
		fclose(SaveBook);

		FILE *CountBook;
		char c;
		int BookCounter = 0;
		
		fopen_s(&CountBook, Storage, "r");
		for ( c=getc(CountBook) ; c != EOF ; c = getc(CountBook) )
		{
			BookCounter++;
		}
		fclose(CountBook);

		printf_s("Total Number of Book in Library = %d", BookCounter);
	}

	else if (user_choice == 2) {

	choose_2: 					printf("%s", "Type Book Name: ");
		scanf_s("%49s", BookName, (unsigned)_countof(BookName));

		FILE *SearchBook;
		int FileOperationResult = 0;
		
		FileOperationResult = fopen_s(&SearchBook, BookName, "r");
		if (!FileOperationResult) {
			fscanf_s(SearchBook, "%19s", BookWriter, (unsigned)_countof(BookWriter));
			fscanf_s(SearchBook, "%99s", BookTopic, (unsigned)_countof(BookTopic));
			fscanf_s(SearchBook, "%d", &BookPageNumber);
			fscanf_s(SearchBook, "%8s", BookPublicationDate, (unsigned)_countof(BookPublicationDate));
			fscanf_s(SearchBook, "%99s", BookPublicationHouse, (unsigned)_countof(BookPublicationHouse));
			fclose(SearchBook);


			printf("\n\nBook Name: %s\n", BookName);
			printf("Book Writer: %s\n", BookWriter);
			printf("Book Topic: %s\n", BookTopic);
			printf("Book Page Number: %d\n", BookPageNumber);
			printf("Book Publication Date: %s\n", BookPublicationDate);
			printf("Book Publication House: %s\n", BookPublicationHouse);
		}

		else
			printf_s("%s", "Something has gone wrong!\n");
		exit(0);

	}

	else {
		printf("%s", "Please press only 0 or 1.. Try again!\n");
		goto choose;
	}

	/*
	printf("\n\n\n%s is the name of book.\n\n", BookName);
	printf("%s is the tutor of book.\n\n", BookWriter);
	printf("%s is the topic of book.\n\n", BookTopic);
	printf("%d is the page of book.\n\n", BookPageNumber);
	printf("%s is the publication date of book.\n\n", BookPublicationDate);
	printf("%s is the publication house of book.\n\n", BookPublicationHouse);

	printf("\n\n%s is title.\n", book.title);
	printf("%s is tutor.\n", book.tutor);
	printf("%s is subject.\n", book.subject);
	printf("%d is total page.\n", book.PageNumber);
	printf("%s is publication date.\n", book.PublicationDate);
	printf("%s is publication house.\n", book.PublicationHouse);
	*/

	return 0;
}