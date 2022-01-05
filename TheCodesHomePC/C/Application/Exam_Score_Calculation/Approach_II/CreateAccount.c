#include "CreateAccount.h"
int create_account(){
	char username[16];
	int password;
	puts("Please type your user name for your new account: ");
	scanf("%15s", username, 16);
	puts("Please enter your password for your new account: ");
	scanf("%d", &password);
	
	// Below, I create a text file with a name of " username "
	// that writes password inside that.
	FILE *USERNAME;
	USERNAME = fopen (username, "w+");
	fprintf(USERNAME, "%d", password);
	fclose(USERNAME);

	return 1;
}

