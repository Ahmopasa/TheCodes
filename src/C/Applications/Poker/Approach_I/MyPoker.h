#ifndef _MATH_H
#include <math.h>
#endif // _MATH_H

#ifndef _STDLIB_H
#include <stdlib.h>
#endif // !_STDLIB_H

#ifndef _STDIO_H
#include <stdio.h>
#endif // !_STDIO_H

#ifndef _TIME_H
#include <time.h>
#endif // !_TIME_H

#ifndef _STRING_H
#include <string.h>
#endif // !_STRING_H

void my_random(void);

typedef struct myGasino {

	char suits[6];
	char pattern[8];
	int raise_status;
	int game_status;
}myPoker;

void userDeckShuffler(myPoker**, size_t total_user);

void userDeckShower(myPoker** , size_t player_number);

void userDeckFolder(myPoker**, size_t player_number);

void boardDeckShuffler(myPoker* board[1][5], size_t from, size_t to);

void boardDeckShow(myPoker* board[1][5], size_t from, size_t to);




