#include "UIScreen.h"
#include "WithCreditCard.h"
#include "WithoutCreditCard.h"
#include "AdminUIScreen.h"

void UIScreen()
{
	
	int firstStepChoice;
	int AdminPassword = 357951;
	line_8 : printf("\t# Welcome #\nPlease choose one below:\n1 - With Credit Card\n2 - Without Credit Card\n");
	scanf("%d", &firstStepChoice);
		switch(firstStepChoice)
		{
			case 1: 
			{
				system("CLS");
				WithCreditCard(); 
				break;
			}
			case 2: 
			{
				system("CLS");
				WithoutCreditCard();
				break;
				
			}
			case 0000: 
			{
				system("CLS");
				ATM_Balance();
				break;
			}
			default : 
			{
				system("CLS");
				printf("\n<<< Please press only '1' or '2' >>>\n\n");
				goto line_8;
			}
		}
}
