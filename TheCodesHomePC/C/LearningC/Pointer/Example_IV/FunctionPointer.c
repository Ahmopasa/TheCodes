#include "FunctionPointer.h"

// Roof : Function Pointer Usage
void foo()
{
	puts("foo was called. ");
}
FPTR GF = (&foo);
void RoofFunc(void)
{
	GF();
}
FPTR Roof_set_func(FPTR fp)
{
	FPTR temp = GF;
	GF = fp;
	return 	temp;
}
void roof_foo()
{
	puts("roof_foo was called. ");
}

int main() {

	RoofFunc(); // foo was called

	FPTR fp = Roof_set_func(&roof_foo);
	RoofFunc();	// roof_foo was called.

	Roof_set_func(fp);
	RoofFunc();	// foo was called

	return 0;
}