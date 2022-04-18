#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buffer.h"


int main() {
	long check;

	printf("Initializes a new circular buffer in memory\n");
	check = init_buffer_421();

	if (check == 0) {
		printf("Initialize Success\n");
	}

	else {
		printf("Initialize Failure\n");
	}

	printf("Inserts up to 20 integers into the next available node\n");
	for (int y=1; y<=20; y++) {
		check = insert_buffer_421(y);
	}

	if (check == 0) {
                printf("Insert Success\n");
        }

        else {
                printf("Insert Failure\n");
	}

	check = print_buffer_421();

	check = delete_buffer_421();

	return 0;
}
