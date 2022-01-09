#include "CheckAccount.h"
#include "CreateAccount.h"

int check_account(){
	
	char username[16];
	int password, saved_password, UserChoice, status = 0;
	TryAgain : printf("%s", "Please type your user name for your existing account: ");
	scanf("%15s",username, 16);
	TryAgain_3: printf("%s", "Please enter your password for your existing account: ");
	scanf("%d", &password);
	
	FILE * Account = fopen(username,"r");
	if (Account == NULL){
	TryAgain_2 : 	puts("Such account could not be found!\nDo you wish to create a new one, or try again re-enterin?\n1- Create a new account.\n2-Try Again.");
		printf("%s", "Choice: ");
		if ( scanf("%d", &UserChoice) == 1 ) {
			
			if ( UserChoice == 1){
				create_account();
				puts("Thanks for creating an account");
			}
			else if ( UserChoice == 2){
				goto TryAgain;
			}
			else {
				puts("Please press only 1 or 2!.");
				goto TryAgain_2;
			}
			}
		else {
			puts("Please enter only integer!.");
			return 0;
		}
		}
		
	else {
	fscanf(Account, "%d", &saved_password);
	fclose(Account);
	}
	
	if ( saved_password == password){
		printf("Information you have entered is correct.\nYour entered password is %d.\nSaved password is %d.\n", password, saved_password);
		status = 1;
	}
	else{
		status = 0;
	}
		
	return status;
	}
	


