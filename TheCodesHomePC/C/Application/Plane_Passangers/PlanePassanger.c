#include "PlanePassanger.h"

int main() {

	int total_passanger = 0;
	int total_plane = 0;
	int user_choice = 0;

	printf_s("%s", "Please, enter total number of plane: ");
	scanf_s("%d", &total_plane);
	printf_s("%s", "Please, enter total number of passanger: ");
	scanf_s("%d", &total_passanger);

	int **Tmp_Pointer = create_array(total_plane, total_passanger);
	printf_s("%s", "\n\n");
	print_array(Tmp_Pointer, total_plane, total_passanger);
	
	return 0;
}