#include <stdio.h>

void func_printf_1(void) {

	puts("I'm Called. (1)");
}

void func_printf_2(void(*func_ptr)(void)) {

	func_ptr = func_printf_1;
	func_ptr();
}


int main() {
	func_printf_1(); // Calling the function func_printf_1 directly.
	puts("");

	void (*func_ptr_1)(void) = func_printf_1;  // Calling the function func_printf_1 using pointer-to-function func_ptr_1.
	func_ptr_1();
	puts("");

	void(*func_ptr_array[3])(void); // Calling the function func_printf_1 using an array of pointer-to-function consist of func_ptr_1's.
	for (int i = 0; i < 3; i++)
	{
		func_ptr_array[i] = func_printf_1;
	}

	for (int i = 0; i < 3; i++)
	{
		func_ptr_array[i]();
	}
	puts("");

	func_printf_2(func_ptr_1);	// Calling the function func_printf_1 using a function its parameter is a pointer-to-function to call func_printf_1.

	return 1;
}
