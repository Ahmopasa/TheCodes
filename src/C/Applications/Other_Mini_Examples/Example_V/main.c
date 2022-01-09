#include <stdio.h>

#define user 10
#define turn 3

struct myCasino
{
	char cardPattern[8];
	char cardSuits[6];
	char cardColor[6];

};
void PlayPoker(struct myCasino myPoker[turn][user][2]);

int main() {

	//////////////////////////////////////////////////////////////////////////////
	my_random();
	struct myCasino myPoker[turn][user][2] = { 0 };
	PlayPoker(myPoker);
	/////////////////////////////////////////////////////////////////////////////
	return 0;

}

void PlayPoker(struct myCasino myPoker[turn][user][2]) {

	const char* suits[13] = { "ACE","TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JOKER", "QUEEN", "KING" };
	const char* color[2] = { "BLACK","RED" };
	const char* pattern[4] = { "HEARTS","TILES", "CLOVERS", "PIKES" };
	int counter;

	struct myCasino onBoard[turn][5] = { 0 };
	for (int i = 0; i < turn; i++)
	{
		int k;
		if (i == 0)
		{
			for (k = 0; k < 3; k++)
			{
				counter = rand();
				strcpy(onBoard[i][k].cardSuits, suits[counter % 13]);
				strcpy(onBoard[i][k].cardColor, color[counter % 2]);
				strcpy(onBoard[i][k].cardPattern, pattern[counter % 4]);
				printf("Turn: %d => (%s)(%s)(%s)\n", i + 1, onBoard[i][k].cardColor, onBoard[i][k].cardPattern, onBoard[i][k].cardSuits);

			}
		}
		else if (i == 1)
		{
			for (int k = 3; k < 4; k++)
			{
				getchar();
				counter = rand();
				strcpy(onBoard[i][k].cardSuits, suits[counter % 13]);
				strcpy(onBoard[i][k].cardColor, color[counter % 2]);
				strcpy(onBoard[i][k].cardPattern, pattern[counter % 4]);
				printf("Turn: %d => (%s)(%s)(%s)\n", i + 1, onBoard[i][k].cardColor, onBoard[i][k].cardPattern, onBoard[i][k].cardSuits);

			}
		}

		else if (i == 2)
		{
			for (int k = 4; k < 5; k++)
			{
				getchar();
				counter = rand();
				strcpy(onBoard[i][k].cardSuits, suits[counter % 13]);
				strcpy(onBoard[i][k].cardColor, color[counter % 2]);
				strcpy(onBoard[i][k].cardPattern, pattern[counter % 4]);
				printf("Turn: %d => (%s)(%s)(%s)\n", i + 1, onBoard[i][k].cardColor, onBoard[i][k].cardPattern, onBoard[i][k].cardSuits);

			}
		}
		puts("");
	}


	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < user; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				counter = rand();
				strcpy(myPoker[i][j][k].cardSuits, suits[counter % 13]);
				strcpy(myPoker[i][j][k].cardColor, color[counter % 2]);
				strcpy(myPoker[i][j][k].cardPattern, pattern[counter % 4]);
				printf("Turn: %d, Player: %d => (%s)(%s)(%s)\n", i + 1, j + 1, myPoker[i][j][k].cardColor, myPoker[i][j][k].cardPattern, myPoker[i][j][k].cardSuits);
			}
			getchar();

		}
		puts("");
	}
}