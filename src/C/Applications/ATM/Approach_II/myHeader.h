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




// It is a function that waits for X second where X is determined by the user.
void sleep_time(double second);

// It let us procude a random number every-time we compile the program.
void my_random();

//The way to calculate the duration
/*
clock_t start = clock();
clock_t end = clock();

%f -> (double)(end - start) / CLOCKS_PER_SEC
*/

//To fill the one dimension array with random numbers
void arrayFillD(int *source, int size);

//To show the one dimension array filled with random numbers
void arrayShowD(const int *source, int size);

//Create One-Dimension Array
int* createArrayD(int size);

//Free One-Dimension Array
int * freeArrayD(int *source);

//Create Two-Dimension Array
int** createArrayDD(int row, int colomn);

//To fill the Two-dimension array with random numbers
void arrayFillDD(int** source, int row, int colomn);

//To show the Two-dimension array filled with random numbers
void arrayShowDD(const int** source, int row, int colomn);

//Free Two-Dimension Array
int ** freeArrayDD(int** source, int row);

//Average Calculation
double average(const int* source, int size);

//Standard Deviation Calculation
void stdDeviation(const int* source, int size, double average);

//MyMiniAtmProgram
void UserScreen(); //Call that function in main() to use ATM program.
void WithCreditCard();
void WithoutCreditCard();
void ControlAccountInfo();
void SendMoney();
void WithdrawMoney();