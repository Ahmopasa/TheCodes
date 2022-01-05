// In this program, one dimension array will be created.
// Malloc will be used.
// Functions are also used.

#include "BusPassangers.h"

int main() {

	int total_passanger = 0;
	printf_s("%s", "Please enter the total number of passanger in a single bus: ");
	scanf_s("%d", &total_passanger);

	int *tmp_pointer = create_array(total_passanger);

	print_array(tmp_pointer, total_passanger);

    change_array(tmp_pointer, total_passanger);
	
	free(tmp_pointer);
    
	return 0;
}