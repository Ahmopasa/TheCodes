#include "AdminUIScreen.h"

int ATM_Balance(){
	
	int atm_balance=0, atm_balance_old;
	int choice=0;
	FILE *ATM_Balance, *ATM_Balance_Old;
	
	line_25 : printf("Please choose below:\n1 - Transferring from bank itself to the ATM Machine.\n2 - Too see remained ATM balance.\n");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1: 
		{
			printf("Please enter the amount you wish to transfer from bank itself to the ATM: ");
			scanf("%lu", &atm_balance);
			
			ATM_Balance_Old = fopen ("ATM_BALANCE.txt", "r");
			while(fscanf(ATM_Balance_Old, "%d", &atm_balance_old) == 1){}
			fclose(ATM_Balance_Old);

			ATM_Balance = fopen ("ATM_BALANCE.txt", "w+");
			fprintf(ATM_Balance, "%d", atm_balance+atm_balance_old);
			fclose(ATM_Balance);		

			ATM_Balance = fopen ("ATM_BALANCE.txt", "r");
			while(fscanf(ATM_Balance, "%d", &atm_balance) == 1)
			{
				printf("%d is the last total amount.\n", atm_balance);
			}
			fclose(ATM_Balance);		
			puts("Process completed!.");
		break;
		}
		case 2: 
		{
			ATM_Balance = fopen ("ATM_BALANCE.txt", "r");
			while(fscanf(ATM_Balance, "%d", &atm_balance) == 1)
			{
				printf("%d", atm_balance);
			}
			fclose(ATM_Balance);
		break;
		}
		default : 
		{
			printf("Please press only '1' or '2'.\n");
			goto line_25;
		}
	}

	return 1;
}
