#include "CalculationForSingleExams.h"
#include "CalculationForWholeExams.h"
#include "CheckAccount.h"
#include "CreateAccount.h"
#include "HeaderFile.h"

int main() {
	
	int UserChoice = 0;
	ChosenChoice: puts("Welcome!\nPlease choose below:\n1- Calculation of Single Exam.\n2- Calculation of Multiple Exams");
	printf("%s", "Your Choice: ");
	if (scanf("%d", &UserChoice) == 1){
		if (UserChoice == 1){
			puts("You have chosen for Calculation of Single Exam.");
			calculator_for_single_exam();
		}
		else if (UserChoice == 2){
			puts("You have chosen for Calculation of Multiple Exam.");
			calculator_for_whole_exams();
		}
		else {
			puts("Please press only 1 or 2!");
			goto ChosenChoice;
		}
	}
	else {
		puts("Please enter only integer numbers!\nPlease restart the program.");
		return 0;
	}

	getchar();
	return 0;
}


