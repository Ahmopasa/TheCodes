#include <stdio.h>
 
typedef struct myGasino {

		char suits[6];
		char color[6];
		char pattern[8];
}myPoker;

int main() {


	myPoker* user[2][2] = { 0 };
	myPoker* board[1][5] = { 0 };

	int counter;

	const char* suits[13] = { "ACE","TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JOKER", "QUEEN", "KING" };
	const char* color[2] = { "BLACK","RED" };
	const char* pattern[4] = { "HEARTS","TILES", "CLOVERS", "PIKES" };

	for (size_t j = 0; j < 2; j++) {
		for (size_t i = 0; i < 2; i++)
		{
			counter = rand();
			user[j][i] = (struct myGasino*)malloc(sizeof(struct myGasino));
			if (user[j][i] == NULL)
			{
				break;
			}
			strcpy(user[j][i]->color, color[counter % 2]);
			strcpy(user[j][i]->suits, suits[counter % 13]);
			strcpy(user[j][i]->pattern, pattern[counter % 4]);
		}
	}

	for (size_t j = 0; j < 2; j++) {
		for (size_t i = 0; i < 2; i++)
		{
			printf("%d. User = (%s) (%s) (%s)\n", i + 1, user[j][i]->suits, user[j][i]->color, user[j][i]->pattern);
		}
		getchar();
	}

	size_t round_turn = 0;
	size_t counter_card = 0;
	for (round_turn = 0; round_turn < 1; round_turn++) {
		for (counter_card = 0; counter_card < 3 ; counter_card++)
		{
			counter = rand();
			board[round_turn][counter_card] = (struct myGasino*)malloc(sizeof(struct myGasino));
			if (board[round_turn][counter_card] == NULL)
			{
				break;
			}
			strcpy(board[round_turn][counter_card]->color, color[counter % 2]);
			strcpy(board[round_turn][counter_card]->suits, suits[counter % 13]);
			strcpy(board[round_turn][counter_card]->pattern, pattern[counter % 4]);
		}
	}
	puts("Press any key to open three card on the board!");
	getchar();
	for (round_turn = 0; round_turn < 1; round_turn++) {
		for (counter_card = 0; counter_card < 3; counter_card++)
		{
			printf("Board = (%s) (%s) (%s)\n", board[round_turn][counter_card]->suits, board[round_turn][counter_card]->color, board[round_turn][counter_card]->pattern);
		}
	}
	return 0;
}
