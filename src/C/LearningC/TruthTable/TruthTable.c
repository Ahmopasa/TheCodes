#include "TruthTable.h"

bool input_1;
bool input_2;

int main() {

	int player_choice = 0;

	printf_s("Welcome to TruthTable.\n");
	printf_s("1- AND Gate\n");
	printf_s("2- OR Gate\n");
	printf_s("3- NOT Gate\n");
	printf_s("4- NAND Gate\n");
	printf_s("5- NOR Gate\n");
	printf_s("6- XOR Gate\n");
	printf_s("7- XNOR Gate\n");
	printf_s("Please choose above to continue: ");
	scanf_s("%d", &player_choice);
	
	bool input_1 = true;
	bool input_2 = true;

	switch (player_choice)
	{
	case 1: {

		AND_Gate(input_1, input_2);
		break;
	}
	case 2: {

		OR_Gate(input_1, input_2);
		break;
	}
	case 3: {

		NOT_Gate(input_1, input_2);
		break;
	}
	case 4: {
		NAND_Gate(input_1, input_2);
		break;
	}
	case 5: {
		NOR_Gate(input_1, input_2);
		break;
	}
	case 6: {
		XOR_Gate(input_1, input_2);
		break;
	}
	case 7: {
		XNOR_Gate(input_1, input_2);
		break;
	}
	default:
		printf_s("Please choose between 1-7!\n");
		break;
	}
	return 0;
}
