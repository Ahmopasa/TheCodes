#include "UIScreen.h"
#include "CalculationForSingleExams.h"
#include "CalculationForWholeExams.h"

int UIScreen(){
	int choice = 0;
	puts("Welcome!\n\nChoose one below:\n1-) Results for Single Exam.\n2-) Results for Multiple Exams.\n");
	scanf("%d", &choice);
	printf("Your choice is %d\n", choice);
	
	if (choice == 1) 
	{ 
		calculator_for_single_exam();
	}
	
	else if (choice == 2) 
	{
		calculator_for_whole_exams();
	}
	
	else 
	{
		puts("Shit Happened!\n");
	}

	return 1;
}
