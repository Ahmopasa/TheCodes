#include<stdio.h>
#include<stdbool.h>

inline void AND_Gate(bool input_1, bool input_2)
{
	printf_s("1- AND Gate\nEvery single input mush to TRUE\n");
	if (input_1 && input_2)
	{
		printf_s("Two Input Is True\n");
	}
	else
	{
		printf_s("One of These Inputs Are Not True\n");
	}
}
inline void OR_Gate(bool input_1, bool input_2)
{
	printf_s("2- OR Gate\nOne of the input must be TRUE\n");
	if (input_1 || input_2)
	{
		printf_s("Two Input Is True\n");
	}
	else
	{
		printf_s("One of These Inputs Are Not True\n");
	}
}
inline void NOT_Gate(bool input_1, bool input_2)
{
	printf_s("3- NOT Gate\nIf input is false, it becomes true.\n");
	printf_s("output_1 is B\n", input_1);
	printf_s("output_2 is B\n", input_2);
}
inline void NAND_Gate(bool input_1, bool input_2)
{
	printf_s("4- NAND Gate\nIf both inputs are TRUE, then output is FALSE\nOtherwise, the output is TRUE\n");
	if (!(input_1 && input_2))
	{
		printf_s("Every single input is TRUE\n");
	}
	else
	{
		printf_s("One of the input or both of the inputs are FALSE\n");
	}
}
inline void NOR_Gate(bool input_1, bool input_2)
{
	printf_s("5- NOR Gate\nIf both inputs are FALSE, then output is TRUE\nOtherwise, the output is FALSE\n");
	if (!(input_1 || input_2))
	{
		printf_s("Every single input is FALSE\n");
	}
	else
	{
		printf_s("One of the input or both of the inputs are TREU\n");
	}
}
inline void XOR_Gate(bool input_1, bool input_2)
{
	printf_s("6- XOR Gate\nIf both of the inputs are both TRUE or FALSE, then the output is FALSE\nOtherwise, the output is TRUE\n");
	if (!(input_1 == input_2))
	{
		printf_s("Both of these inputs are either TRUE or FALSE\n");
	}
	else
	{
		printf_s("On of these inputs are either TRUE of FALSE\n");
	}
}
inline void XNOR_Gate(bool input_1, bool input_2)
{
	printf_s("7- XNOR Gate\nIf both of the inputs are both TRUE or FALSE, then the output is TRUE\nOtherwise, the output is FALSE\n");
	if (input_1 == input_2)
	{
		printf_s("Both of these inputs are either TRUE or FALSE\n");
	}
	else
	{
		printf_s("On of these inputs are either TRUE of FALSE\n");
	}
}



