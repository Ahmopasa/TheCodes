#include "ATM.h"

#define CLEAR system("CLS");

void clearBuffer(void)
{
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF)
		;
}

void ToString(const int PinCode, char* PinCodeString)
{
	snprintf(PinCodeString, 4, "%d", PinCode);
}

void ui_screen(void)
{
	AccountOwner customer = {"XXXX", "XXXX", "XXXX", 9999, 9999, 9999 };
	printf("Welcome to the ATM Machine. Please, enter your name and PIN code to proceed.\n");
	printf("< If you do not have any PIN code, or it is not reachable, please press 9999. >\n");

	while (1)
	{
		printf("PinCode : ");
		int PinCode;
		if (scanf("%d", &PinCode)) {
			clearBuffer();
			if (PinCode == 9999)
			{
				printf("[WIP : Welcome to the account save page.]\n"); continue; //TODO #2
			}
			else if (PinCode < 0)
			{
				printf("You have entered a valid input, but it was below zero. Please, make sure that you have entered a positive numeric value.\n"); continue;
			}
			else
			{
				ReadAccountInfo(PinCode, &customer);
				printf("Welcome => %s.\n", customer.Name);
				printf("What would you like to do?\n");
				printf("0- Exit.\n");
				printf("1- See Account Information.\n");
				printf("2- Deposit Cash.\n");
				printf("3- Withdraw Cash.\n");
				
				while (1)
				{
					printf("Choice: ");
					int choice;
					if (scanf("%d", &choice))
					{
						clearBuffer();
						if (choice == 0)
						{
							printf("Exiting from program by request.\n"); exit(EXIT_SUCCESS);
						}
						else if (choice == 1)
						{
							CheckAccountInfo(&customer); break;
						} 
						else if (choice == 2)
						{
							DepositCurrency(&customer); break;
						}
						else if (choice == 3)
						{
							WithdrawCurrency(&customer); break;
						}
						else
						{
							printf("Please, enter a value between 0 - 3\n"); continue;
						}
					}
					else
					{
						printf("Please, enter a numeric value.\n"); clearBuffer(); continue;
					}
				}
			}
		}
		else
		{
			printf("Please, enter a numeric value.\n"); clearBuffer(); continue;
		}
	}
}

void ReadAccountInfo(const int PinCode, AccountOwner* customer)
{
	char tempString[4];
	ToString(PinCode, tempString);

	FILE* FileHandler = fopen(tempString, "r");
	if (!FileHandler)
	{
		printf("Failed to open file : %s. [WIP : Would you like to create a new account? (Y / N)]\n", tempString); exit(EXIT_FAILURE);
	}
	char tempName[10];
	char tempSurname[10];
	char tempAddress[10];
	int tempBalance;
	int tempVipStatus;
	if (fscanf(FileHandler, "%s %s %s %d %d", tempName, tempSurname, tempAddress, &tempBalance, &tempVipStatus) == 5)
	{
		memcpy(customer->Name, tempName, 10);
		memcpy(customer->Surname, tempSurname, 10);
		memcpy(customer->Address, tempAddress, 10);
		customer->Balance = tempBalance;
		customer->AccountVipStatus = tempVipStatus;
		customer->AccountPINCode = PinCode;
	}
	fclose(FileHandler);
}

void ChangeAccountInfo(AccountOwner* customer)
{
	printf("Which piece of information would you like to change?\n");
	printf("To Exit:            0\n");
	printf("To Change Name:     1\n");
	printf("To Change Surname:  2\n");
	printf("To Change Address:  3\n");
	printf("To Change PIN Code: 4\n");

	while (1)
	{
		printf("Choice: ");
		unsigned int choice;
		if (scanf("%d", &choice) == 1)
		{
			switch (choice)
			{
				case 0:
				{
					printf("Exiting from program by request.\n"); exit(EXIT_SUCCESS);
				}
				case 1:
				{
					while (1)
					{
						printf("Please, enter a new name for < %s > : ", customer->Name);
						char name[10];
						if (scanf("%s", name) == 1)
							memcpy(customer->Name, name, 10);
						else
						{
							printf("Changing the name for < %s > has failed. Try Again.\n", customer->Name); continue;
						}
					}
				}
				case 2:
				{
					while (1)
					{
						printf("Please, enter a new surname for < %s > : ", customer->Surname);
						char surname[10];
						if (scanf("%s", surname) == 1)
							memcpy(customer->Surname, surname, 10);
						else
						{
							printf("Changing the surname for < %s > has failed. Try Again.\n", customer->Surname); continue;
						}
					}
				}
				case 3:
				{
					while (1)
					{
						printf("Please, enter a new address for < %s > : ", customer->Address);
						char address[10];
						if (scanf("%s", address) == 1)
							memcpy(customer->Address, address, 10);
						else
						{
							printf("Changing the address for < %s > has failed. Try Again.\n", customer->Address); continue;
						}
					}
				}
				case 4:
				{
					while (1)
					{
						printf("Please, enter a new Pin Code for < %d > : ", customer->AccountPINCode);
						int PinCode;
						if (scanf("%d", &PinCode) == 1)
							customer->AccountPINCode = PinCode;
						else
						{
							printf("Changing the Pin Code for < %d > has failed. Try Again.\n", customer->AccountPINCode); continue;
						}
					}
				}
				default:
				{
					printf("Please, enter a numeric value between 1 - 4.\n"); clearBuffer(); continue;
				}
			}
		}
		else
		{
			printf("Please, enter a numeric value.\n"); clearBuffer(); continue;
		}
	}
}

void CheckAccountInfo(const AccountOwner* customer)
{
	printf("Name               : %s\n", customer->Name);
	printf("Surname            : %s\n", customer->Surname);
	printf("Address            : %s\n", customer->Address);
	printf("Balance            : %d\n", customer->Balance);
	printf("Pin Code           : %d\n", customer->AccountPINCode);
	printf("Account VIP Status : %d\n", customer->AccountVipStatus);
}

void DepositCurrency(AccountOwner* customer)
{
	printf("How much TL will you deposit %s? : ", customer->Name);
	while (1)
	{
		int depositAmount;
		if (scanf("%d", &depositAmount) && depositAmount > 0)
		{
			customer->Balance += depositAmount; SaveAccountInfo(customer); break;

			if (customer->Balance > 1000000)
			{
				customer->AccountVipStatus = 1; break;
			}
			else
			{
				customer->AccountVipStatus = 0; break;
			}
		}
		else if (depositAmount < 0)
		{
			printf("You have entered a valid input, but it was below zero. Please, make sure that you have entered a positive cash value. Enter a new cash amount : "); clearBuffer();
		}
		else
		{
			printf("You have entered an invalid cash amount. Please, make sure that you have entered a numeric value : "); clearBuffer();
		}
	}

	printf("%s has %dTL in his/her bank account.\n", customer->Name, customer->Balance);
}

void WithdrawCurrency(AccountOwner* customer)
{
	printf("How much TL will you withdraw %s? : ", customer->Name);
	while (1)
	{
		int withdrawAmount;
		if (scanf("%d", &withdrawAmount) && withdrawAmount > 0 && withdrawAmount <= (int)customer->Balance)
		{
			customer->Balance -= withdrawAmount; SaveAccountInfo(customer); break;

			if (customer->Balance < 1000000)
			{
				customer->AccountVipStatus = 0; break;
			}
			else
			{
				customer->AccountVipStatus = 1; break;
			}
		}
		else if (withdrawAmount < 0)
		{
			printf("You have entered a valid input, but it was below zero. Please, make sure that you have entered a positive cash value. Enter a new cash amount : "); clearBuffer();
		}
		else
		{
			printf("You have entered an invalid cash amount. Please, make sure that you have entered a numeric value : "); clearBuffer();
		}
	}

	printf("%s has %dTL in his/her bank account.\n", customer->Name, customer->Balance);
}

void SaveAccountInfo(const AccountOwner* customer)
{
	char tempString[4];
	ToString(customer->AccountPINCode, tempString);

	FILE* FileHandler = fopen(tempString, "w+");
	if (!FileHandler)
	{
		printf("Failed to open file : %s. [WIP : Would you like to create a new account? (Y / N)]\n", tempString); exit(EXIT_FAILURE);
	}

	if (fprintf(FileHandler, "%s\n%s\n%s\n%d\n%d", customer->Name, customer->Surname, customer->Address, customer->Balance, customer->AccountVipStatus) == 5)
		;
	fclose(FileHandler);
}
