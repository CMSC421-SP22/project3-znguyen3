#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "buffer_sem.h"

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

	sleep(10);

	printf("Inserts up to 20 integers into the next available node\n");

	//producer
	for (int i = 0; i<= 1000; i++) {
		char data[1024] = {1};

		//critical section
		sleep(.001 + (rand() / 1.11));
		check = enqueue_buffer_421(data);
	}

	// consumer
	for (int i = 0; i<= 1000; i++) {
                char data[1024] = {0};

		//critical section
                sleep(.001 + (rand() / 1.11));
                check = dequeue_buffer_421(data);
        }

	printf("Success\n");


	check = delete_buffer_421();

         if (check == 0) {
                printf("Delete Success\n");
        }

        else {
                printf("Delete Failure\n");
        }

	return 0;
}
