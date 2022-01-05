#include <stdio.h>

#define user 10
#define turn 3

struct myCasino
{
	char cardPattern[8];
	char cardSuits[6];
	char cardColor[6];

};

void deckShuffer(struct myCasino myPoker[turn][user][2]);

int main() {

	//////////////////////////////////////////////////////////////////////////////
	my_random();
	struct myCasino myPoker[turn][user][2] = { 0 };
	deckShuffer(myPoker);
	/////////////////////////////////////////////////////////////////////////////
	return 0;

}

void deckShuffer(struct myCasino myPoker[turn][user][2]) {


	const char* suits[13] = { "ACE","TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JOKER", "QUEEN", "KING" };
	const char* color[2] = { "BLACK","RED" };
	const char* pattern[4] = { "HEARTS","TILES", "CLOVERS", "PIKES" };
	int counter = rand();

	int i = 0, turn_counter = 0;
	puts("***********************************");
	for ( i = 0; i < 1; i++)
	{
		for (int j = 0; j < user; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				counter = rand();
				strcpy(myPoker[i][j][k].cardSuits, suits[counter % 13]);
				strcpy(myPoker[i][j][k].cardColor, color[counter % 2]);
				strcpy(myPoker[i][j][k].cardPattern, pattern[counter % 4]);
				printf("Turn: %d, Player: %d => (%s)(%s)(%s)\n", turn_counter+1, j+1, myPoker[i][j][k].cardColor, myPoker[i][j][k].cardPattern, myPoker[i][j][k].cardSuits);
			}
		}
	}
	turn_counter++;
	getchar();
	puts("***********************************");
	for (i = 0; i < 1; i++)
	{
		for (int j = 0; j < user; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				counter = rand();
				strcpy(myPoker[i][j][2].cardSuits, suits[counter % 13]);
				strcpy(myPoker[i][j][2].cardColor, color[counter % 2]);
				strcpy(myPoker[i][j][2].cardPattern, pattern[counter % 4]);
				printf("Turn: %d, Player: %d => (%s)(%s)(%s)\n", turn_counter+1, j + 1, myPoker[i][j][k].cardColor, myPoker[i][j][k].cardPattern, myPoker[i][j][k].cardSuits);

			}
		}
	}
	turn_counter++;
	getchar();
	puts("***********************************");
	for (i = 0; i < 1; i++)
	{
		for (int j = 0; j < user; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				counter = rand();
				strcpy(myPoker[i][j][3].cardSuits, suits[counter % 13]);
				strcpy(myPoker[i][j][3].cardColor, color[counter % 2]);
				strcpy(myPoker[i][j][3].cardPattern, pattern[counter % 4]);
				printf("Turn: %d, Player: %d => (%s)(%s)(%s)\n", turn_counter+1, j + 1, myPoker[i][j][k].cardColor, myPoker[i][j][k].cardPattern, myPoker[i][j][k].cardSuits);
			}
		}
	}
	puts("***********************************");
