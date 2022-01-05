#define _CRT_SECURE_NO_WARNINGS

#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define		PUBLIC
#define		PRIVATE				static

#define		YEARBASE			1900
#define		RANDOM_YEAR_MIN		1940
#define		RANDOM_YEAR_MAX		2010
#define		NPLUS				6

#define		isleap(y)			((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))
#define		mday(y, m)			daytabs[isleap(y)][m]

//private function declarations

PRIVATE int is_valid_date(int d, int m, int y);
PRIVATE Date *set(Date *p, int d, int m, int y);
PRIVATE int totaldays(const Date *p);
PRIVATE Date* to_date(Date *p, int totaldays);
PRIVATE Date* to_date(Date *p, int totaldays);


PRIVATE const int daytabs[][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
};

/*      public functions   */

//----------------------------------------------------------------------------------------------------------

PUBLIC Date *set_date(Date *p, int d, int m, int y)
{
	return set(p, d, m, y);
}

//----------------------------------------------------------------------------------------------------------

PUBLIC Date *set_today(Date *p)
{
	time_t timer;
	time(&timer);
	struct tm* tp = localtime(&timer);
	int d = tp->tm_mday;
	int m = tp->tm_mon + 1;
	int y = tp->tm_year + 1900;

	return set(p, d, m, y);
}
//----------------------------------------------------------------------------------------------------------

PUBLIC Date *set_date_from_str(Date *p, const char *pstr)
{
	int d = atoi(pstr);
	int m = atoi(pstr + 3);
	int y = atoi(pstr + 6);

	return set(p, d, m, y);
}
//----------------------------------------------------------------------------------------------------------

PUBLIC Date *set_random_date(Date *p)
{
	int y = rand() % (RANDOM_YEAR_MAX - RANDOM_YEAR_MIN + 1) + RANDOM_YEAR_MIN;
	int m = rand() % 12 + 1;
	int d = rand() % mday(y, m) + 1;

	return set(p, d, m, y);
}
//----------------------------------------------------------------------------------------------------------

PUBLIC Date *set_month_day(Date *p, int d)
{
	int m = p->mm;
	int y = p->my;

	return set(p, d, m, y);
}

//----------------------------------------------------------------------------------------------------------

PUBLIC Date *set_month(Date *p, int m)
{
	int d = p->md;
	int y = p->my;

	return set(p, d, m, y);
}

//----------------------------------------------------------------------------------------------------------
PUBLIC Date *set_year(Date *p, int y)
{
	int d = p->md;
	int m = p->mm;

	return set(p, d, m, y);
}

//----------------------------------------------------------------------------------------------------------
// getters

PUBLIC int get_month_day(const Date *p)
{
	return p->md;
}

//----------------------------------------------------------------------------------------------------------

PUBLIC int get_month(const Date *p)
{
	return p->mm;
}

//----------------------------------------------------------------------------------------------------------

PUBLIC int get_year(const Date *p)
{
	return p->my;
}

//----------------------------------------------------------------------------------------------------------

PUBLIC int get_week_day(const Date *p)
{
	return (totaldays(p) + NPLUS) % 7;
}

//----------------------------------------------------------------------------------------------------------

PUBLIC int get_year_day(const Date *p)
{
	int sum = p->md;

	for (int i = 1; i < p->mm; ++i) {
		sum += mday(p->my, i);
	}

	return sum;
}

//----------------------------------------------------------------------------------------------------------

PUBLIC int get_date_diff(const Date *p1, const Date *p2)
{
	return abs(totaldays(p1) - totaldays(p2));
}

//----------------------------------------------------------------------------------------------------------

PUBLIC int cmp_date(const Date *p1, const Date *p2)
{
	if (p1->my != p2->my)
		return p1->my - p2->my;

	if (p1->mm != p2->mm)
		return p1->mm - p2->mm;

	return p1->md - p2->md;
}

//----------------------------------------------------------------------------------------------------------

//input - output

PUBLIC void print_date(FILE *f, const Date *p)
{
	static const char *const pmons[] = {
	"",
	"Ocak",
	"Subat",
	"Mart",
	"Nisan",
	"Mayis",
	"Haziran",
	"Temmuz",
	"Agustos",
	"Eylul",
	"Ekim",
	"Kasim",
	"Aralik"
	};
	static const char *const pdays[] = {
	"Pazartesi",
	"Sali",
	"Carsamba",
	"Persembe",
	"Cuma",
	"Cumartesi",
	"Pazar",
	};

	fprintf(f, "%02d %s %d %s\n", p->md, pmons[p->mm], p->my, pdays[get_week_day(p)]);
}

//----------------------------------------------------------------------------------------------------------

PUBLIC Date* scan_date(Date *p)
{
	int d, m, y;
	//clear_input_buffer();
	scanf("%d%d%d", &d, &m, &y);

	return set(p, d, m, y);
}

//----------------------------------------------------------------------------------------------------------
PUBLIC Date *increment(Date *p, int n)
{
	return ndays(p, p, n);
}
//----------------------------------------------------------------------------------------------------------

PUBLIC Date *decrement(Date *p, int n)
{
	return ndays(p, p, -n);
}

//----------------------------------------------------------------------------------------------------------

PUBLIC Date *ndays(Date *pdest, const Date *psource, int n)
{
	return to_date(pdest, totaldays(psource) + n);
}


/*      private functions    */
//----------------------------------------------------------------------------------------------------------

PRIVATE int is_valid_date(int d, int m, int y)
{
	return y >= YEARBASE && m > 0 && m <= 12 && d > 0 && d <= mday(y, m);
}

//----------------------------------------------------------------------------------------------------------

PRIVATE Date *set(Date *p, int d, int m, int y)
{
	if (!is_valid_date(d, m, y)) {
		printf("gecersiz tarih olustu: %d-%d-%d\n", d, m, y);
		exit(EXIT_FAILURE);
	}
	p->md = d;
	p->mm = m;
	p->my = y;

	return p;
}
//----------------------------------------------------------------------------------------------------------

PRIVATE int totaldays(const Date *p)
{
	int sum = get_year_day(p);

	for (int i = YEARBASE; i < p->my; ++i)
		sum += isleap(i) ? 366 : 365;

	return sum;
}

//----------------------------------------------------------------------------------------------------------

PRIVATE Date* to_date(Date *p, int totaldays)
{
	int y = YEARBASE;

	while (totaldays > (isleap(y) ? 366 : 365)) {
		totaldays -= (isleap(y) ? 366 : 365);
		++y;
	}

	int m = 1;

	while (totaldays > mday(y, m)) {
		totaldays -= mday(y, m);
		++m;
	}
	int d = totaldays;

	return set(p, d, m, y);
}

//----------------------------------------------------------------------------------------------------------
