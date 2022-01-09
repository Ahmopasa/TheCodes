#include "MyPoker.h"


int main()
{
	int total_user = 0;
	int little_blind = 5;
	int big_blind = little_blind * 2;
	int balancePool = little_blind + big_blind;
	//int balancePool = 0;

	puts("Welcome to my poker game.");
	printf("How many will players play the game?\nTotal User: ");
	if (!((scanf("%d", &total_user)) && total_user >= 2 && total_user <= 10)) {
		puts("Total User Must Be Between 2 and 10!");
		exit(1);
	}
	//system("cls");
	printf("Total User = %d\n", total_user);

	my_random();

	myPoker** user = (myPoker**)malloc(total_user * sizeof(myPoker*));
	if (*user == NULL)
	{
		puts("1-) Memory Allocation was failed.");
		exit(1);
	}
	for (int i = 0; i < 8; i++)
	{
		user[i] = (myPoker*)malloc(8 * sizeof(myPoker));
		if (*user == NULL)
		{
			puts("2-) Memory Allocation was failed.");
			exit(1);
		}
	}
	userDeckShuffler(user, total_user);
	for (int i = 0; i < total_user; i++)
	{
		userDeckShower(user, i);
	}
	getchar();
	//system("cls");
	myPoker* board[1][5];
	//boardDeckShuffler(board, 0, 3);
	//puts("Cards were being distributed. Cards on be board;");
	//boardDeckShow(board, 0, 3);





	//system("cls");
	//puts("\n\nAll Cards on the Board;");
	//boardDeckShow(board, 0, 5);

	for (int i = 0; i < total_user; i++)
	{
		user[i]->raise_status = 0;
		user[i]->game_status = 1;
	}
	int flag = 0; // to check if someone made an increasement to the big_blind.

	printf("\nBalance: %d\n", balancePool);
	printf("Big Blind: %d\n", big_blind);
	int turn_counter = 1;
	int player_counter = total_user; // used to check to see total number of people who are up.
	//int dealer = rand() % total_user;
	int dealer = 0;
	int PlayerToPlay = (dealer + 1) % total_user;
	printf("Dealer: Player %d\n\n", dealer);
	int player_action;
	int player_blind_rise;

	int the_player;
	while (turn_counter <= 3) {
		switch (turn_counter)
		{
		case 1:
		{
			puts("Turn: The Flop (3)");


			for (int i = PlayerToPlay; i < ((PlayerToPlay + total_user)); i++)
			{
				the_player = (i + 2) % total_user;
				if (player_counter == 1)
				{
					printf("\n\nWinner: Player %d\n\n", the_player); exit(1);
				}
			try_again: printf("Total Balance: %d\nMinimum Bid: %d\nIt us player %d's turn.\nChoose one below;\n(1) -Fold your cards.\n(2) -Raise the blind.\n(3) -Call.\nChoice: ", balancePool, big_blind,the_player);
				if (scanf("%d", &player_action));
				if (player_action == 1)
				{
					userDeckFolder(user, the_player);
					user[the_player]->game_status = 0;
					user[the_player]->raise_status = 0;
					printf("Player %d's Decks;\n", the_player);
					userDeckShower(user, the_player);
					--player_counter;
				}
				else if (player_action == 2)
				{
				TryAgain_rise: printf("How much you would like to increase the blind? (min. %d): ", big_blind);
					if (scanf("%d", &player_blind_rise) && player_blind_rise >= big_blind)
					{
						big_blind = player_blind_rise;
						balancePool += player_blind_rise;
						user[the_player]->raise_status = big_blind;
						flag = 1;
					}
					else
					{
						printf("Please, make an increasement bigger than %d.\n", big_blind);
						goto TryAgain_rise;
					}
				}
				else if (player_action == 3)
				{
					printf("I called.\n\n");
					balancePool += big_blind;
					user[the_player]->raise_status = big_blind;
				}
				else
				{
					puts("Please, choose between 1-3.");
					goto try_again;
				}
			}
			puts("");
			puts("");
			puts("");
			if (flag)
			{
				if (player_counter == 1)
				{
					printf("\n\nWinner: Player %d\n\n", the_player % total_user); exit(1);
				}
				for (int i = the_player; (i) < (total_user + the_player); i++)
				{
					if (user[i % total_user]->game_status != 0 && user[i % total_user]->raise_status != big_blind)
					{
					try_again_2: printf("Total Balance: %d\nMinimum Bid: %d\nPlayer %d, choose below. You need to make a new blind. Min. %d.\n", balancePool, big_blind,i % total_user, big_blind);
						printf("(1) - To Fold\n");
						printf("(2) - To Raise\n");
						printf("(3) - To Call\n");
						if (scanf("%d", &player_action));
						if (player_action == 1)
						{
							userDeckFolder(user, i % total_user);
							user[i % total_user]->game_status = 0;
							user[i % total_user]->raise_status = 0;
							printf("Player %d's Decks;\n", i % total_user);
							userDeckShower(user, i % total_user);
							--player_counter;
						}
						else if (player_action == 2)
						{
						increase_again: printf("Player %d, how much you would like to incrase? Min. %d : ", i % total_user, big_blind);
							if (scanf("%d", &player_blind_rise) && player_blind_rise >= big_blind)
							{
								big_blind = player_blind_rise;
								balancePool += player_blind_rise;
								user[i % total_user]->raise_status = player_blind_rise;
								flag = 1;
							}
							else
							{
								printf("Player %d, minimum increase: %d.\n", i % total_user, big_blind);
								goto increase_again;
							}
						}
						else if (player_action == 3)
						{
							printf("I called.\n\n");
							balancePool += big_blind;
							user[i % total_user]->raise_status = big_blind;
						}
						else
						{
							puts("Please, choose between 1-3.");
							goto try_again_2;
						}
					}
					else if (user[i % total_user]->game_status == 0)
					{
						//printf("Player %d cannot make a new blind since his game status %d\n", i % total_user, user[i % total_user]->game_status);
					}
					else if (user[i % total_user]->game_status != 0 && user[i % total_user]->raise_status == big_blind)
					{
						//printf("Player %d cannot make a new blind since he made biggest blind.(%d)\n", i % total_user, user[i % total_user]->raise_status);
					}
				}
			}
			puts("");
			puts("");
			puts("");

			boardDeckShuffler(board, 0, 3);
			puts("Cards were being distributed. Cards on be board;");
			boardDeckShow(board, 0, 3);
			turn_counter++;
			break;
		}
		case 2:
		{
			puts("\n\nTurn: The Turn (4)");
			for (int i = PlayerToPlay; i < (PlayerToPlay + total_user); i++)
			{
				the_player = (i + 2) % total_user;
				if (user[the_player]->game_status == 0)
				{
					continue;
				}
				else
				{
					if (player_counter == 1)
					{
						printf("\n\nWinner: Player %d\n\n", the_player); exit(1);
					}
					printf("Minimum blind: %d\n", big_blind);
					printf("Total Balance Pool: %d\n", balancePool);
				try_again_3: printf("Player %d, please choose one below;\n", the_player);
					printf("(1) - To Fold.\n");
					printf("(2) - To Raise.\n");
					printf("(3) - To Call.\n");
					if (scanf("%d", &player_action));
					if (player_action == 1)
					{
						userDeckFolder(user, the_player);
						user[the_player]->raise_status = 0;
						user[the_player]->game_status = 0;
						printf("Player %d's Decks;\n", the_player);
						userDeckShower(user, the_player);
						--player_counter;
					}
					else if (player_action == 2)
					{
					TryAgain_rise_3: printf("Player %d, How much raise you wish to do? (Min. is %d) :", the_player, big_blind);
						if (scanf("%d", &player_blind_rise) && player_blind_rise >= big_blind)
						{
							flag = 1;
							big_blind = player_blind_rise;
							balancePool += player_blind_rise;
							user[the_player]->raise_status = big_blind;
						}
						else
						{
							printf("Please, make an increasement bigger than %d.\n", big_blind);
							goto TryAgain_rise_3;
						}
					}
					else if (player_action == 3)
					{
						printf("I called.\n");
						balancePool += big_blind;
						user[the_player]->raise_status = big_blind;
					}
					else
					{
						puts("Please, choose between 1-3.");
						goto try_again_3;
					}

				}
			}
			if (flag)
			{
				printf("\n\n\nSomeone increased the big blind. Min. Bid: %d.\n", big_blind);
				for (int j = the_player + 1; j < (j + total_user); j++)
				{
					j %= total_user;
					if (user[j]->game_status != 0 && user[j]->raise_status != big_blind)
					{
					try_again_4: printf("Player %d, you must make an increasement or fold your cards. \n(1) to raise.\n(2) to fold.\n(3) to call.\n", j);
						if (scanf("%d", &player_action));
						if (player_action == 1)
						{
						TryAgain_rise_4: printf("How much increasement you will do? ( Min. Bid: %d): ", big_blind);
							if (scanf("%d", &player_blind_rise) && player_blind_rise >= big_blind)
							{
								big_blind = player_blind_rise;
								balancePool += player_blind_rise;
								user[j]->raise_status = big_blind;

							}
							else
							{
								printf("Please, make an increasement bigger than %d.\n", big_blind);
								goto TryAgain_rise_4;
							}
						}
						else if (player_action == 2)
						{
							userDeckFolder(user, j);
							user[j]->raise_status = 0;
							user[j]->game_status = 0;
							printf("Player %d's Decks;\n", j);
							userDeckShower(user, j);
							--player_counter;
						}
						else if (player_action == 3)
						{
							printf("I called.\n");
							balancePool += big_blind;
							user[j]->raise_status = big_blind;
						}
						else
						{
							puts("Please, choose between 1-2.");
							goto try_again_4;
						}

					}
				}
			}




			puts("\n\nBlinds were done. Time to see 4rd card on the board.");
			boardDeckShuffler(board, 3, 4);
			puts("\n\n4th card on the board;");
			boardDeckShow(board, 3, 4);
			turn_counter++;
			break;
		}
		case 3:
		{
			puts("Turn: The River (5)");





			puts("\n5th card on the board;");
			boardDeckShuffler(board, 4, 5);
			boardDeckShow(board, 4, 5);
			turn_counter++;
			break;
		}
		default:
		{
			puts("Turn: Game Over"); exit(1);
		}

		}

	}

}