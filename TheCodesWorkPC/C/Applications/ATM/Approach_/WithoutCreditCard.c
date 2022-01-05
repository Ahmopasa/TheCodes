#include "WithoutCreditCard.h"

int WithoutCreditCard()
{
	int choice,choice2,amount, UserID,Saved_User_ID,atm_balance_old,user_balance_old, destination_balance_old, destination_ID, Saved_Destination_ID;
	FILE *USER_ID,*ATM_Balance,*ATM_Balance_Old,*USER_Balance_Old,*USER_Balance, *DESTINATION_Balance_Old, *DESTINATION_Balance, *DESTINATION_ID;
	
	line7: printf("Please choose below:\n1- To Personal Account.\n2- To Another Account.\nChoice: ");
	scanf("%d", &choice);
	if(choice == 1)
	{
		printf("Please enter your personal ID: ");
		scanf("%d", &UserID);
		
		USER_ID = fopen("USER_ID.txt","r");
		while(fscanf(USER_ID, "%d", &Saved_User_ID) == 1){}
		fclose(USER_ID);
		
		if (UserID == Saved_User_ID)
		{
			printf("ID is true. Now, do you wish to deposit, or withdraw? ( 1: Deposit, 2: Withdraw)\n");
			scanf("%d", &choice2);
			switch(choice2)
			{
				case 1: 
				{
					printf("Enter the amount you wish to deposit: ");
					scanf("%d", &amount);
					
					ATM_Balance_Old = fopen ("ATM_BALANCE.txt", "r");
					while(fscanf(ATM_Balance_Old, "%d", &atm_balance_old) == 1){}
					fclose(ATM_Balance_Old);
					ATM_Balance = fopen ("ATM_BALANCE.txt", "w+");
					fprintf(ATM_Balance, "%d", atm_balance_old+amount);
					fclose(ATM_Balance);
			
					USER_Balance_Old = fopen ("USER_BALANCE.txt", "r");
					while(fscanf(USER_Balance_Old, "%d", &user_balance_old) == 1){}
					fclose(USER_Balance_Old);

					USER_Balance = fopen ("USER_BALANCE.txt", "w+");
					fprintf(USER_Balance, "%d", user_balance_old+amount);
					fclose(USER_Balance);		
				break;
				}
				case 2: 
				{
					printf("\nPlease enter the amount you wish to withdraw: ");
					scanf("%d", &amount);

					ATM_Balance_Old = fopen ("ATM_BALANCE.txt", "r");
					while(fscanf(ATM_Balance_Old, "%d", &atm_balance_old) == 1){}
					fclose(ATM_Balance_Old);

					ATM_Balance = fopen ("ATM_BALANCE.txt", "w+");
					fprintf(ATM_Balance, "%d", atm_balance_old-amount);
					fclose(ATM_Balance);
		
					USER_Balance_Old = fopen ("USER_BALANCE.txt", "r");
					while(fscanf(USER_Balance_Old, "%d", &user_balance_old) == 1){}
					fclose(USER_Balance_Old);

					USER_Balance = fopen ("USER_BALANCE.txt", "w+");
					fprintf(USER_Balance, "%d", user_balance_old-amount);
					fclose(USER_Balance);	
				break;
				}
			}
		}
	}
	else if(choice == 2) 
	{
		line69: printf("Please choose below: \n1- Withdraw\n2- Deposit\nChoice: ");
		scanf("%d",&choice2);
		switch(choice2)
		{
			case 1: 
			{
				line_74: printf("Please enter the ID of destination account: ");
				scanf("%d", &destination_ID);				
			
				DESTINATION_ID = fopen("DESTINATION_ID.txt.txt","r");
				while(fscanf(DESTINATION_ID, "%d", &Saved_Destination_ID) == 1){}
				fclose(DESTINATION_ID);
				
				if (Saved_Destination_ID == destination_ID)
				{				
					printf("Please enter the amount you wish to withdraw: ");
					scanf("%d", &amount);
					DESTINATION_Balance_Old = fopen ("DESTINATION_BALANCE.txt.txt", "r");
					while(fscanf(DESTINATION_Balance_Old, "%d", &destination_balance_old) == 1){}
					fclose(DESTINATION_Balance_Old);
	
					DESTINATION_Balance = fopen ("DESTINATION_BALANCE.txt.txt", "w+");
					fprintf(DESTINATION_Balance, "%d", destination_balance_old-amount);
					fclose(DESTINATION_Balance);	
				
					ATM_Balance_Old = fopen ("ATM_BALANCE.txt", "r");
					while(fscanf(ATM_Balance_Old, "%d", &atm_balance_old) == 1){}
					fclose(ATM_Balance_Old);
			
					ATM_Balance = fopen ("ATM_BALANCE.txt", "w+");
					fprintf(ATM_Balance, "%d", atm_balance_old-amount);
					fclose(ATM_Balance);				
				}
			
				else if (Saved_Destination_ID != destination_ID)
				{
					printf("WRONG DESTINATION ID\n");
					goto line_74;
				}	

			break;
			}
			case 2: 
			{
				line_116: 	printf("Please enter the ID of destination account: ");
				scanf("%d", &destination_ID);
				
					DESTINATION_ID = fopen("DESTINATION_ID.txt.txt","r");
					while(fscanf(DESTINATION_ID, "%d", &Saved_Destination_ID) == 1){}
					fclose(DESTINATION_ID);
					
					if (Saved_Destination_ID == destination_ID)
					{						
						printf("Please enter the amount you wish to deposit: ");
						scanf("%d", &amount);
						DESTINATION_Balance_Old = fopen ("DESTINATION_BALANCE.txt.txt", "r");
						while(fscanf(DESTINATION_Balance_Old, "%d", &destination_balance_old) == 1){}
						fclose(DESTINATION_Balance_Old);
			
						DESTINATION_Balance = fopen ("DESTINATION_BALANCE.txt.txt", "w+");
						fprintf(DESTINATION_Balance, "%d", destination_balance_old+amount);
						fclose(DESTINATION_Balance);	
						
						ATM_Balance_Old = fopen ("ATM_BALANCE.txt", "r");
						while(fscanf(ATM_Balance_Old, "%d", &atm_balance_old) == 1){}
						fclose(ATM_Balance_Old);
				
						ATM_Balance = fopen ("ATM_BALANCE.txt", "w+");
						fprintf(ATM_Balance, "%d", atm_balance_old+amount);
						fclose(ATM_Balance);
					}
					else if (Saved_Destination_ID != destination_ID)
					{
						printf("WRONG DESTINATION ID\n");
						goto line_116;
					}
			break;
			}
			default: 
			{
				printf("ONLY 1 OR 2\n");
				goto line69;
			}
		}
	}
	else 
	{
		printf("PlEaSe PrEsS OnLy 1 Or 2!!!\n");
		goto line7;
	}

	return 1;
}
