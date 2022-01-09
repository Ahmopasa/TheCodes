#include "WithCreditCard.h"

int WithCreditCard(){
	line_4:	puts("Please enter your personal ID\n");
	int User_ID, choice, choice_2,WithdrawAmount, Saved_User_ID;
	int atm_balance=0,atm_balance_old=0, user_balance, user_balance_old, destination_balance_old, Saved_Destination_ID, destination_ID;
	// errno;
	
	scanf("%d", &User_ID);
	CLEAR
	FILE *USER_ID, *ATM_Balance_Old, *ATM_Balance, *USER_Balance, *USER_Balance_Old, *DESTINATION_Balance, *DESTINATION_Balance_Old, *DESTINATION_ID;

	USER_ID = fopen("USER_ID.txt","r");
	while(fscanf(USER_ID, "%d", &Saved_User_ID) == 1){}
	fclose(USER_ID);
		
	if (Saved_User_ID == User_ID)
	{
		line_15 :printf("Please choose one from:\n1 - To withdraw money.\n2 - To deposit money.\n\nChoice: ");
		scanf("%d", &choice);
			
		switch(choice)
		{
			case 1: 
			{
				printf("\nPlease enter the amount you wish to withdraw: ");
				scanf("%d", &WithdrawAmount);

				ATM_Balance_Old = fopen ("ATM_BALANCE.txt", "r");
				while(fscanf(ATM_Balance_Old, "%d", &atm_balance_old) == 1){}
				fclose(ATM_Balance_Old);
		
				ATM_Balance = fopen ("ATM_BALANCE.txt", "w+");
				fprintf(ATM_Balance, "%d", atm_balance_old-WithdrawAmount);
				fclose(ATM_Balance);
				
				USER_Balance_Old = fopen ("USER_BALANCE.txt", "r");
				while(fscanf(USER_Balance_Old, "%d", &user_balance_old) == 1){}
				fclose(USER_Balance_Old);
		
				USER_Balance = fopen ("USER_BALANCE.txt", "w+");
				fprintf(USER_Balance, "%d", user_balance_old-WithdrawAmount);
				fclose(USER_Balance);		

			break;
			}
			case 2: 
			{
				line_46 :printf("Please choose one below:\n1 - To my current account.\n2 - To another person's account.\nChoice: ");
				scanf("%d", &choice_2);
				
				if(choice_2 == 1)
				{
					printf("Please enter the amount you wish to deposit: ");
					int DepositAmount;
					scanf("%d", &DepositAmount);
					
					USER_Balance_Old = fopen ("USER_BALANCE.txt", "r");
					while(fscanf(USER_Balance_Old, "%d", &user_balance_old) == 1){}
					fclose(USER_Balance_Old);
		
					USER_Balance = fopen ("USER_BALANCE.txt", "w+");
					fprintf(USER_Balance, "%d", user_balance_old+DepositAmount);
					fclose(USER_Balance);	
					
					ATM_Balance_Old = fopen ("ATM_BALANCE.txt", "r");
					while(fscanf(ATM_Balance_Old, "%d", &atm_balance_old) == 1){}
					fclose(ATM_Balance_Old);
			
					ATM_Balance = fopen ("ATM_BALANCE.txt", "w+");
					fprintf(ATM_Balance, "%d", atm_balance_old+DepositAmount);
					fclose(ATM_Balance);
				}
				else if (choice_2 == 2)
				{
					
					line_76: printf("Please enter the ID of destination account you wish to deposit: ");
					scanf("%d", &destination_ID);
					
					DESTINATION_ID = fopen("DESTINATION_ID.txt.txt","r");
					if (DESTINATION_ID == NULL) 
					{
							puts("No ID Acount Could Be Found\n");
							printf("%d is Error No.\n", errno);
							goto line_46;	
					}

					while(fscanf(DESTINATION_ID, "%d", &Saved_Destination_ID) == 1){}
					fclose(DESTINATION_ID);

					if (Saved_Destination_ID == destination_ID) 
					{
						printf("Please enter the amount you wish to deposit: ");
						int DepositAmount;
						scanf("%d", &DepositAmount);

						DESTINATION_Balance_Old = fopen ("DESTINATION_BALANCE.txt.txt", "r");
						while(fscanf(DESTINATION_Balance_Old, "%d", &destination_balance_old) == 1){}
						fclose(DESTINATION_Balance_Old);
			
						DESTINATION_Balance = fopen ("DESTINATION_BALANCE.txt.txt", "w+");
						fprintf(DESTINATION_Balance, "%d", destination_balance_old+DepositAmount);
						fclose(DESTINATION_Balance);	
						
						ATM_Balance_Old = fopen ("ATM_BALANCE.txt", "r");
						while(fscanf(ATM_Balance_Old, "%d", &atm_balance_old) == 1){}
						fclose(ATM_Balance_Old);
				
						ATM_Balance = fopen ("ATM_BALANCE.txt", "w+");
						fprintf(ATM_Balance, "%d", atm_balance_old+DepositAmount);
						fclose(ATM_Balance);
					}
					else 
					{
						printf("WRONG DESTINATION ID\n");
						goto line_76;
					}		
				}
				else 
				{
					printf("Please be careful!\n");
					goto line_46;
				}
			
			break;
			}
			default : 
			{
				system("CLS");
				printf("Please Press Only '1' or '2'.\n");
				goto line_15;
			}
		}
	}
	else
	{
		system("CLS");
		puts("Could not find any account.\n");
		goto line_4;
	}
	return 1;
}

		
