#include "myHeader.h"
#include <conio.h>

#define TOP_LEVEL 100

void sleep_time(double second) {
	clock_t start = clock();
	while (((double)clock() - start) / CLOCKS_PER_SEC - second)
		; // null statement
}

void my_random() {
	srand((unsigned)time(NULL));
}

//The way to calculate the duration
/*
clock_t start = clock();
clock_t end = clock();

%f -> (double)(end - start) / CLOCKS_PER_SEC
*/

double average(const int* source, int size) {
	printf("Inside of arrayStdDev Function\n");
	int counter = size;
	int counter2 = size;

	int total = 0;
	while (counter--) {
		total += *source++;
	}
	printf("Total = %d\n", total);

	double average = (double)total / size;
	printf("Average = %lf\n", average);
	return average;
}

void stdDeviation(const int* source, int size, double average) {
	double sum_sqr = 0;
	for (int i = 0; i < size; i++)
	{
		sum_sqr += (source[i] - average) * (source[i] - average);
	}

	printf("Std. Devi. = %lf\n", sqrt(sum_sqr / size));

}

void  arrayFillD(int* source, int size) {
	my_random();
	printf("Inside of arrayFillD Function\n");
	for (int i = 0; i < size; i++)
	{
		source[i] = rand() % TOP_LEVEL;
	}
}

void arrayShowD(const int* source, int size) {
	printf("Inside of arrayShowD Function\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d. element = %d\n", i, source[i]);
	}

	//while (size--) {
	//	printf("%d. index = %d\n", size, *source++);
	//}
}

int* createArrayD(int size) {

	int* myArray = (int*)malloc(size * sizeof(int*));
	if (myArray == NULL)
	{
		printf("Memory could not be allocated!\n");
		exit(1);
	}
	else
	{
		printf("Memory was be allocated for D!\n");
		return myArray;
	}
	
}

int** createArrayDD(int row, int colomn) {
	
	int** myArray = malloc(row * sizeof(int*));
	if (myArray == NULL)
	{
		printf("Memory could not be allocated!\n");
		exit(1);
	}
	else
	{
		for (int i = 0; i < row; i++)
		{
			myArray[i] = malloc(colomn * sizeof(int));
			if (myArray[i] == NULL)
			{
				printf("Memory could not be allocated!\n");
				exit(1);
			}
		}
		printf("Memory was be allocated for DD!\n");
		return myArray;
	}
}

void arrayFillDD(int** source, int row, int colomn) {
	my_random();
	printf("Inside of arrayFillDD Function\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < colomn; j++)
		{
			source[i][j] = rand() % TOP_LEVEL;
		}
	}

}

void arrayShowDD(const int** source, int row, int colomn) {
	printf("Inside of arrayShowDD Function\n");
	int counter = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < colomn; j++)
		{
			printf("%d. index = %d\n",counter, source[i][j]);
			counter++;
		}
	}
}

int* freeArrayD(int* source) {
	free(source);
	source = NULL;

	return source;
}

int** freeArrayDD(int** source, int row) {
	for (int i = 0; i < row; i++)
	{
		free(source[i]);
		source[i] = NULL;
	}
	free(source);
	source = NULL;

	return source;
}


void UserScreen()
{
	int user_choice = 0;

	printf("## Welcome ##\n");
	printf("Please choose below:\n");
	printf("1- (With)Personal Account Card\n");
	printf("2- (Without)Personal Account Card\n");
	printf("Choice: ");
	if (scanf("%d", &user_choice) == 1)
	{
		switch (user_choice)
		{
		case 1: WithCreditCard(); break;
		case 2: WithoutCreditCard(); break;
		default: printf("Please, choose 1 or 2!\n");
		}
	}
	else if (scanf("%d", &user_choice) == 0)
		printf("Please, choose 1 or 2!\n");
}

void WithCreditCard() {
	printf("You've called the function WithCreditCard()\n");

	int user_pin = 0;
	int saved_user_pin = 0;

	int entered_cash_amount = 0;
	int saved_cash_amount = 0;

	char user_card_name[10] = {0};

	printf("Please, insert your card & enter your PIN number\n");
	printf("PIN NO: ");
	if (scanf("%d", &user_pin))
	{
		printf("User Card Name: ");
		if (scanf("%s", user_card_name))
		{
			FILE* account_info;
			account_info = fopen(user_card_name, "r");
			if (account_info == NULL)
			{
				printf("Such account could not be found!\n");
				exit(1);
			}
			if (fscanf(account_info, "%d %d", &saved_user_pin, &saved_cash_amount) && saved_user_pin == user_pin)
			{
				fclose(account_info);
				
				int user_choice = 0;
				printf("Informations you have entered are correct!\nWelcome %s. Please choose below:\n", user_card_name);
				printf("1- Send Cash\n");
				printf("2- Withdraw Cash\n");
				printf("3- Check Account Info\n");
				if (scanf("%d", &user_choice) == 1)
				{
					switch (user_choice)
					{
					case 1: ControlAccountInfo(); break;
					case 2: SendMoney(); break;
					case 3: WithdrawMoney(); break;
					default: printf("Please, choose only 1, 2 or 3!\n");
					}
				}
				else if (scanf("%d", &user_choice) == 0)
				{
					printf("Please, choose only 1, 2 or 3!\n");
				}
			}
			else
			{
				printf("Such account could not be found!\n");
			}
		}
	}	
}
void WithoutCreditCard() {
	printf("You've called the function WithoutCreditCard()\n");
}

void ControlAccountInfo() { printf("You have called the function ControlAccountInfo()"); }
void SendMoney() { printf("You have called the function SendMoney()"); }
void WithdrawMoney() { printf("You have called the function WithdrawMoney()"); }


