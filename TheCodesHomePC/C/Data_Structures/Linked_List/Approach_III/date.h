#ifndef DATE_H
#define DATE_H

struct _iobuf;
typedef struct _iobuf FILE;

typedef struct {
	int md, mm, my; //private
}Date;

//setters / mutators
Date* set_date(Date *p, int d, int m, int y);
Date* set_today(Date *p);
Date* set_date_from_str(Date *p, const char *ps); //gg/aa/yyyy
Date* set_random_date(Date *p);

Date* set_month_day(Date *p, int d);
Date* set_month(Date *p, int m);
Date* set_month_day(Date *p, int y);
Date* increment(Date *p, int n);
Date* decrement(Date *p, int n);

//getters - accessors
int get_month_day(const Date *);  
int get_month(const Date *);
int get_year(const Date *);
int get_week_day(const Date *);
int get_year_day(const Date *);

//utility function
int cmp_date(const Date *p1, const Date *p2);
Date* ndays(Date *pdest, const Date *psource, int n);
int get_date_diff(const Date *p1, const Date *p2);

//formatted input-output functions
void print_date(FILE *f, const Date *p);
Date* scan_date(Date *p);

#endif
