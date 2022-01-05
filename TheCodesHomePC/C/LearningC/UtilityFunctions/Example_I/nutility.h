#ifndef	NUTILITY_H
#define NUTILITY_H

#include <stddef.h>

#define  asize(x)			(sizeof(x) / sizeof(*x))
#define  isleap(y)			((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))
#define  econ32(x)			((((x) >> 8) & 0x0000FF00) | (((x) << 8) & 0x00FF0000) | (((x) >> 24) & 0x000000FF) | ((x) << 24))
#define  econ16(x)			(((x) >> 8) & 0x00FF | ((x) << 8))
#define sbc(x)				(sbc_[(x) & 0xFF] +  sbc_[((x) >> 8) & 0xFF] + sbc_[((x) >> 16) & 0xFF] + sbc_[((x) >> 24) & 0xFF]) 

extern const int sbc_[];


int		ndigit(int val);
int		isprime(int val);
void	sl(void);
void	sleep(double sec);
void	swap(int *p1, int *p2);
int		day_of_week(int d, int m, int y);
void	randomize(void);
void	display_array(const int *p, size_t size);
void	set_random_array(int *p, size_t size);
void	bsort(int *p, size_t size);
void	quick_sort(int *p, size_t size);
char*	sgets(char *ptr);
void	gswap(void *vp1, void  *vp2, size_t n);
void*	checked_malloc(size_t n);
double	drand(void);
void	bprint(int);

#endif





