#ifndef  NUTILITY_INCLUDED
#define  NUTILITY_INCLUDED

#include <stddef.h>

extern const int sbc_[];

#define  asize(x)    (sizeof(x) / sizeof(*x))
#define  sbc(x)		 (sbc_[(x) & 0xFF] + sbc_[((x) >> 8) & 0xFF] + sbc_[((x) >> 16) & 0xFF] + sbc_[((x) >> 24) & 0xFF])
#define Swap4Bytes(x) ((((x) >> 24) & 0x000000FF) |    \
                      (((x) >> 8) & 0x0000FF00)   |    \
                      (((x) << 8) & 0x00FF0000)   |    \
                      ((x) << 24))

#define		isleap(y)		((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))


int		isprime(int x);
void	sl(void);
void	sleep(double sec);
int		ndigit(int x);
void	randomize(void);
void	sgets(char *p);

void	set_random_array(int *p, size_t size);
void	display_array(const int *p, size_t size);
void	sort(int *p, size_t size);
void    swap(int *p, int *p2);
void	gswap(void *vp1, void *vp2, size_t n);
void    bprint(int val);

const char* random_name(void);
const char* random_fname(void);
const char* random_town(void);


#endif