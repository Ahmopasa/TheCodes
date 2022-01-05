#include "CalculationForSingleExams.h"
#include "CheckAccount.h"


//Here, average score will be calculated as well as succeed rate etc. 



int calculator_for_single_exam ()
{	
	int result_check_account = check_account();

	int i,j,k;
	
	if ( result_check_account == 1) 
	{	
		srand(time(NULL));
		int total_students=2 + rand()%20;
		int ID[total_students];
		int Grade[total_students];
		int Total_Grade=0;
		int succeed=0;
		int MinimumGrade=0;

		printf("Please enter the minimum grade: ");
		scanf("%d", &MinimumGrade);

		for (i=0;i<total_students;i++)
		{
			ID[i] = rand()%99999;
			Grade[i]= rand()%100;
			Total_Grade += Grade[i];
			if (Grade[i] > MinimumGrade)
			{
				succeed++;
			}
		}
		puts("\n#\tID\tGrade");
		for (i=0;i<total_students;i++)
		{
			printf("%d.\t%d\t%d\n", i+1, ID[i], Grade[i]);
		}
		printf("\nTotal number of students who joined the exam: %d\n", total_students);
		printf("Average Score is %.2f\n", (float)Total_Grade/total_students);
		printf("Succeed Rate is %.2f", (float)100*succeed/total_students);
		printf("\nTotal Succeed Students: %d", succeed);
		
		return 1;
	}

	return 0;
}






