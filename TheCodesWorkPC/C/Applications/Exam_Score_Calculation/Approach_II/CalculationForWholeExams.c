#include "CalculationForWholeExams.h"
#include "CheckAccount.h"

int i,j,k;

int calculator_for_whole_exams(){
	
	int result_check_account = check_account();	
	if ( result_check_account == 1) 
	{
		srand(time(NULL));

		int ExamNumber = 0;
		int total_students = 0;

		printf("%s", "Please enter total number of exam: ");
		scanf("%d", &ExamNumber);
		printf("%s", "Please enter total number of students: ");
		scanf("%d", &total_students);

		int ExamScoreList[ExamNumber][total_students];
		int ID[total_students];
		int TotalGrade[total_students];

		int MinimumGrade = 60, success = 0;

		//Will fill Exam Score List
		for ( i=0;i<total_students;i++)
		{
			for(j=0;j<ExamNumber;j++) 
			{
				//rintf("Please enter %d. Grade for Exam_%d = ", i+1, j+1);
				//scanf("%d", &ExamScoreList[i][j]);
				ExamScoreList[i][j] = 0 + rand()%101;
				TotalGrade[i] += ExamScoreList[i][j];
				if ( (TotalGrade[i]/ExamNumber) > 60)
				{
					success++;
				}
			}
			
			printf("\n");
		}

		//Will fill the ID list
		for ( i=0;i<total_students;i++)
		{
			//printf("Please enter %d. student's grade: ", i+1);
			//scanf("%d", &ID[i]);
			ID[i] = 200 + rand()%450;
		}

		//Will print Whole List.
		printf("%s", "ID\t");
		for( i=0;i<ExamNumber;i++)
		{
			printf("Exam %d\t", i+1);
		}

		printf("%s", "Average Score");
		printf("\n");
		for ( i=0;i<total_students;i++)
		{
			printf("%d\t", ID[i]);
			for(j=0;j<ExamNumber;j++) 
			{
				printf("%d\t", ExamScoreList[i][j]);
			}
			printf("%.2f", (float)TotalGrade[i]/ExamNumber);
			printf("\n");
		}

		// Will print results
		printf("\nTotal Number of Students: %d\n", total_students);
		printf("Total Number of Exam(s): %d\n", ExamNumber);
		printf("Total Number of Successfull Students: %d\n", success);
		printf("Success Rate is %.2f", (float)100*success/total_students);

		return 1;
	}

	return 0;
}



