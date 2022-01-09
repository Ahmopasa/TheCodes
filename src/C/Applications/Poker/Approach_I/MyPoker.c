#include "MyPoker.h"


void my_random(void) {
	srand((unsigned)time(NULL));
}

void userDeckShuffler(myPoker** user, size_t total_user) {

	const char* const card_suits[13] = { "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JOKER", "QUEEN", "KING", "ACE" };
	const char* const card_pattern[4] = { "HEARTS","TILES", "CLOVERS", "PIKES" };
	
	my_random();
	int  randomize = 0;

	for (size_t i = 0; i < total_user; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			randomize = rand();
			strcpy(user[i][j].suits, card_suits[randomize % 13]);
			strcpy(user[i][j].pattern, card_pattern[randomize % 4]);
		}
	}

}

void userDeckShower(myPoker** user, size_t player_number) {

	for (size_t i = player_number; i < player_number + 1; i++) {
		printf("Player %d's Cards;\n", i);
	
		for (size_t j = 0; j < 2; j++)
		{
			printf("(%s) of (%s)\n", user[i][j].pattern, user[i][j].suits);
		}
		puts("");
	}
}

void userDeckFolder(myPoker** user, size_t player_number) {

	for (size_t i = player_number; i < player_number + 1; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			strcpy(user[i][j].suits, " ");
			strcpy(user[i][j].pattern, " ");

		}
	}


}

void boardDeckShuffler(myPoker* board[1][5], size_t from, size_t to) {
	
	const char* const suits[13] = { "ACE","TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JOKER", "QUEEN", "KING" };
	const char* const pattern[4] = { "HEARTS","TILES", "CLOVERS", "PIKES" };

	for (size_t i = 0; i < 1; i++) {
		for (size_t j = from; j < to; j++)
		{
			
			board[i][j] = (struct myGasino*)malloc(sizeof(struct myGasino));
			if (board[i][j] == NULL)
			{
				break;
			}
			strcpy(board[i][j]->suits, suits[rand() % 13]);
			strcpy(board[i][j]->pattern, pattern[rand() % 4]);
		}
	}

}

void boardDeckShow(myPoker* board[1][5], size_t from, size_t to) {

	for (size_t i = 0; i < 1; i++) {
		for (size_t j = from; j < to; j++)
		{
			printf("Board = (%s) (%s)\n", board[i][j]->suits, board[i][j]->pattern);
		}
	}

}



