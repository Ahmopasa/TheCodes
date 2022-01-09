#include "MyATM.h"

static FILE* USER_ID;
static FILE* ATM_Balance_Old;
static FILE* ATM_Balance;
static FILE* USER_Balance;
static FILE* USER_Balance_Old;
static FILE* DESTINATION_Balance;
static FILE* DESTINATION_Balance_Old;
static FILE* DESTINATION_ID;

void ui_screen()
{
	int first_step_choice;
line_8: printf("\t# Welcome #\nPlease choose one below:\n1 - With Credit Card\n2 - Without Credit Card\n");
	if (scanf("%d", &first_step_choice));
	switch (first_step_choice) {
	case 1: {
		CLEAR
			WithCreditCard();
		break;
	}
	case 2: {
		CLEAR
			WithoutCreditCard();
		break;
	}
	case 0: {
		CLEAR
			ATMBalance();
		break;
	}
	default: {
		CLEAR
			printf("\n<<< Please press only '1' or '2' >>>\n\n");
		goto line_8;
	}
	}
}

static void ATMBalance() {
	int atm_balance = 0, atm_balance_old;
	int choice = 0;

line_25: printf("Please choose below:\n1 - Transferring from bank itself to the ATM Machine.\n2 - Too see remained ATM balance.\n");
	if (scanf("%d", &choice));

	switch (choice) {
	case 1: {
		printf("Please enter the amount you wish to transfer from bank itself to the ATM: ");
		if (scanf("%d", &atm_balance));

		ATM_Balance_Old = fopen("ATM_BALANCE.txt", "r");
		while (fscanf(ATM_Balance_Old, "%d", &atm_balance_old) == 1) {
		}
		fclose(ATM_Balance_Old);

		ATM_Balance = fopen("ATM_BALANCE.txt", "w+");
		fprintf(ATM_Balance, "%d", atm_balance + atm_balance_old);
		fclose(ATM_Balance);

		ATM_Balance = fopen("ATM_BALANCE.txt", "r");
		while (fscanf(ATM_Balance, "%d", &atm_balance) == 1) {
			printf("%d is the last total amount.\n", atm_balance);
		}
		fclose(ATM_Balance);
		puts("Process completed!.");
		break;
	}
	case 2: {
		ATM_Balance = fopen("ATM_BALANCE.txt", "r");
		while (fscanf(ATM_Balance, "%d", &atm_balance) == 1) {
			printf("%d", atm_balance);
		}
		fclose(ATM_Balance);
		break;
	}
	default: {
		printf("Please press only '1' or '2'.\n");
		goto line_25;
	}
	}
}

static void WithCreditCard() {
line_4:	puts("Please enter your personal ID\n");
	int User_ID, choice, choice_2, WithdrawAmount, Saved_User_ID;
	int atm_balance = 0, atm_balance_old = 0, user_balance_old, destination_balance_old, Saved_Destination_ID, destination_ID;

	if (scanf("%d", &User_ID));
	CLEAR

		USER_ID = fopen("USER_ID.txt", "r");
	while (fscanf(USER_ID, "%d", &Saved_User_ID) == 1) {}
	fclose(USER_ID);

	if (Saved_User_ID == User_ID) {
	line_15:printf("Please choose one from:\n1 - To withdraw money.\n2 - To deposit money.\n\nChoice: ");

		if (scanf("%d", &choice));

		switch (choice) {
		case 1: {
			printf("\nPlease enter the amount you wish to withdraw: ");
			if (scanf("%d", &WithdrawAmount));

			ATM_Balance_Old = fopen("ATM_BALANCE.txt", "r");
			while (fscanf(ATM_Balance_Old, "%d", &atm_balance_old) == 1) {}
			fclose(ATM_Balance_Old);

			ATM_Balance = fopen("ATM_BALANCE.txt", "w+");
			fprintf(ATM_Balance, "%d", atm_balance_old - WithdrawAmount);
			fclose(ATM_Balance);

			USER_Balance_Old = fopen("USER_BALANCE.txt", "r");
			while (fscanf(USER_Balance_Old, "%d", &user_balance_old) == 1) {}
			fclose(USER_Balance_Old);

			USER_Balance = fopen("USER_BALANCE.txt", "w+");
			fprintf(USER_Balance, "%d", user_balance_old - WithdrawAmount);
			fclose(USER_Balance);

			break;
		}
		case 2: {
		line_46:printf("Please choose one below:\n1 - To my current account.\n2 - To another person's account.\nChoice: ");
			if (scanf("%d", &choice_2));

			if (choice_2 == 1) {
				printf("Please enter the amount you wish to deposit: ");
				int DepositAmount;
				if (scanf("%d", &DepositAmount));

				USER_Balance_Old = fopen("USER_BALANCE.txt", "r");
				while (fscanf(USER_Balance_Old, "%d", &user_balance_old) == 1) {}
				fclose(USER_Balance_Old);

				USER_Balance = fopen("USER_BALANCE.txt", "w+");
				fprintf(USER_Balance, "%d", user_balance_old + DepositAmount);
				fclose(USER_Balance);

				ATM_Balance_Old = fopen("ATM_BALANCE.txt", "r");
				while (fscanf(ATM_Balance_Old, "%d", &atm_balance_old) == 1) {}
				fclose(ATM_Balance_Old);

				ATM_Balance = fopen("ATM_BALANCE.txt", "w+");
				fprintf(ATM_Balance, "%d", atm_balance_old + DepositAmount);
				fclose(ATM_Balance);
			}
			else if (choice_2 == 2) {
			line_76: printf("Please enter the ID of destination account you wish to deposit: ");
				if (scanf("%d", &destination_ID));

				DESTINATION_ID = fopen("DESTINATION_ID.txt", "r");
				if (DESTINATION_ID == NULL) {
					puts("No ID account Could Be Found\n");
					printf("%d is Error No.\n", errno);
					goto line_46;
				}

				while (fscanf(DESTINATION_ID, "%d", &Saved_Destination_ID) == 1) {}
				fclose(DESTINATION_ID);

				if (Saved_Destination_ID == destination_ID) {
					printf("Please enter the amount you wish to deposit: ");
					int DepositAmount;
					if (scanf("%d", &DepositAmount));

					DESTINATION_Balance_Old = fopen("DESTINATION_BALANCE.txt", "r");
					while (fscanf(DESTINATION_Balance_Old, "%d", &destination_balance_old) == 1) {}
					fclose(DESTINATION_Balance_Old);

					DESTINATION_Balance = fopen("DESTINATION_BALANCE.txt", "w+");
					fprintf(DESTINATION_Balance, "%d", destination_balance_old + DepositAmount);
					fclose(DESTINATION_Balance);

					ATM_Balance_Old = fopen("ATM_BALANCE.txt", "r");
					while (fscanf(ATM_Balance_Old, "%d", &atm_balance_old) == 1) {}
					fclose(ATM_Balance_Old);

					ATM_Balance = fopen("ATM_BALANCE.txt", "w+");
					fprintf(ATM_Balance, "%d", atm_balance_old + DepositAmount);
					fclose(ATM_Balance);
				}
				else {
					printf("WRONG DESTINATION ID\n");
					goto line_76;
				}
			}
			else {
				printf("Please be careful!\n");
				goto line_46;
			}
			break;
		}
		default: {
			CLEAR
				printf("Please Press Only '1' or '2'.\n");
			goto line_15;
		}
		}
	}
	else {
		CLEAR
			puts("Could not find any account.\n");
		goto line_4;
	}
}

static void WithoutCreditCard() {
	int choice, choice2, amount, UserID, Saved_User_ID, atm_balance_old, user_balance_old, destination_balance_old, destination_ID, Saved_Destination_ID;
	// FILE* USER_ID, * ATM_Balance, * ATM_Balance_Old, * USER_Balance_Old, * USER_Balance, * DESTINATION_Balance_Old, * DESTINATION_Balance, * DESTINATION_ID;

line7: printf("Please choose below:\n1- To Personal Account.\n2- To Another Account.\nChoice: ");
	if (scanf("%d", &choice));
	if (choice == 1) {
		printf("Please enter your personal ID: ");
		if (scanf("%d", &UserID));

		USER_ID = fopen("USER_ID.txt", "r");
		while (fscanf(USER_ID, "%d", &Saved_User_ID) == 1) {}
		fclose(USER_ID);

		if (UserID == Saved_User_ID) {
			printf("ID is true. Now, do you wish to deposit, or withdraw? ( 1: Deposit, 2: Withdraw)\n");
			if (scanf("%d", &choice2));
			switch (choice2) {
			case 1: { printf("Enter the amount you wish to deposit: ");
				if (scanf("%d", &amount));

				ATM_Balance_Old = fopen("ATM_BALANCE.txt", "r");
				while (fscanf(ATM_Balance_Old, "%d", &atm_balance_old) == 1) {}
				fclose(ATM_Balance_Old);
				ATM_Balance = fopen("ATM_BALANCE.txt", "w+");
				fprintf(ATM_Balance, "%d", atm_balance_old + amount);
				fclose(ATM_Balance);

				USER_Balance_Old = fopen("USER_BALANCE.txt", "r");
				while (fscanf(USER_Balance_Old, "%d", &user_balance_old) == 1) {}
				fclose(USER_Balance_Old);

				USER_Balance = fopen("USER_BALANCE.txt", "w+");
				fprintf(USER_Balance, "%d", user_balance_old + amount);
				fclose(USER_Balance);
				break;
			}
			case 2: {
				printf("\nPlease enter the amount you wish to withdraw: ");
				if (scanf("%d", &amount));

				ATM_Balance_Old = fopen("ATM_BALANCE.txt", "r");
				while (fscanf(ATM_Balance_Old, "%d", &atm_balance_old) == 1) {}
				fclose(ATM_Balance_Old);

				ATM_Balance = fopen("ATM_BALANCE.txt", "w+");
				fprintf(ATM_Balance, "%d", atm_balance_old - amount);
				fclose(ATM_Balance);

				USER_Balance_Old = fopen("USER_BALANCE.txt", "r");
				while (fscanf(USER_Balance_Old, "%d", &user_balance_old) == 1) {}
				fclose(USER_Balance_Old);

				USER_Balance = fopen("USER_BALANCE.txt", "w+");
				fprintf(USER_Balance, "%d", user_balance_old - amount);
				fclose(USER_Balance);
				break;
			}
			}
		}
	}
	else if (choice == 2) {
	line69: 	printf("Please choose below: \n1- Withdraw\n2- Deposit\nChoice: ");
		if (scanf("%d", &choice2));
		switch (choice2) {
		case 1: {
		line_74: 	printf("Please enter the ID of destination account: ");
			if (scanf("%d", &destination_ID));

			DESTINATION_ID = fopen("DESTINATION_ID.txt", "r");
			while (fscanf(DESTINATION_ID, "%d", &Saved_Destination_ID) == 1) {}
			fclose(DESTINATION_ID);

			if (Saved_Destination_ID == destination_ID) {
				printf("Please enter the amount you wish to withdraw: ");
				if (scanf("%d", &amount));
				DESTINATION_Balance_Old = fopen("DESTINATION_BALANCE.txt", "r");
				while (fscanf(DESTINATION_Balance_Old, "%d", &destination_balance_old) == 1) {}
				fclose(DESTINATION_Balance_Old);

				DESTINATION_Balance = fopen("DESTINATION_BALANCE.txt", "w+");
				fprintf(DESTINATION_Balance, "%d", destination_balance_old - amount);
				fclose(DESTINATION_Balance);

				ATM_Balance_Old = fopen("ATM_BALANCE.txt", "r");
				while (fscanf(ATM_Balance_Old, "%d", &atm_balance_old) == 1) {}
				fclose(ATM_Balance_Old);

				ATM_Balance = fopen("ATM_BALANCE.txt", "w+");
				fprintf(ATM_Balance, "%d", atm_balance_old - amount);
				fclose(ATM_Balance);
			}
			else {
				printf("WRONG DESTINATION ID\n");
				goto line_74;
			}
			break;
		}
		case 2: {
		line_116: 	printf("Please enter the ID of destination account: ");
			if (scanf("%d", &destination_ID));

			DESTINATION_ID = fopen("DESTINATION_ID.txt", "r");
			while (fscanf(DESTINATION_ID, "%d", &Saved_Destination_ID) == 1) {}
			fclose(DESTINATION_ID);

			if (Saved_Destination_ID == destination_ID) {
				printf("Please enter the amount you wish to deposit: ");
				if (scanf("%d", &amount));
				DESTINATION_Balance_Old = fopen("DESTINATION_BALANCE.txt", "r");
				while (fscanf(DESTINATION_Balance_Old, "%d", &destination_balance_old) == 1) {}
				fclose(DESTINATION_Balance_Old);

				DESTINATION_Balance = fopen("DESTINATION_BALANCE.txt", "w+");
				fprintf(DESTINATION_Balance, "%d", destination_balance_old + amount);
				fclose(DESTINATION_Balance);

				ATM_Balance_Old = fopen("ATM_BALANCE.txt", "r");
				while (fscanf(ATM_Balance_Old, "%d", &atm_balance_old) == 1) {}
				fclose(ATM_Balance_Old);

				ATM_Balance = fopen("ATM_BALANCE.txt", "w+");
				fprintf(ATM_Balance, "%d", atm_balance_old + amount);
				fclose(ATM_Balance);
			}
			else {
				printf("WRONG DESTINATION ID\n");
				goto line_116;
			}
			break;
		}
		default: {
			printf("ONLY 1 OR 2\n");
			goto line69;
		}
		}
	}
	else {
		printf("PlEaSe PrEsS OnLy 1 Or 2!!!\n");
		goto line7;
	}
}
