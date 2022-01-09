#include <string.h>

#define size 100

int main() {

	char filename[size];
	char new__fileName[size];

	printf("Enter file name: ");
	scanf("%s", filename);
	strcpy(new__fileName, filename);
	printf("1. (%s) -> (%s)\n", filename, new__fileName);

	char* p = strrchr(new__fileName, '.');
	if (p == NULL)
	{
		strcat(new__fileName, ".txt");
		printf("2. (%s) -> (%s)\n", filename, new__fileName);
	}
	else if (!strcmp(p, ".jpg"))
	{
		strcpy(p, ".jpeg");
		printf("3. (%s) -> (%s)\n", filename, new__fileName);
	}
	else if (!strcmp(p, ".xls"))
	{
		strcpy(p,"");
		printf("4. (%s) -> (%s)\n", filename, new__fileName);
	}
	else
	{
		strcpy(p, ".dat");
		printf("5. (%s) -> (%s)\n", filename, new__fileName);
	}
}
