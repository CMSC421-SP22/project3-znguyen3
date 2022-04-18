#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include <linux/kernel.h>
#include <sys/syscall.h>
//#include <sys/slab.h>

#define __NR_init_buffer_421 442
#define __NR_insert_buffer_421 443
#define __NR_print_buffer_421 444
#define __NR_delete_buffer_421 445

long init_buffer_421(void) {
	return syscall(__NR_init_buffer_421);
}

long insert_buffer_421(int i) {
	return syscall(__NR_insert_buffer_421, i);
}

long print_buffer_421(void) {
	return syscall(__NR_print_buffer_421);
}

long delete_buffer_421(void) {
	return syscall(__NR_delete_buffer_421);
}

int main() {
	long check;

	printf("Initializes a new circular buffer in memory\n");
	check = init_buffer_421();

	printf("%d\n", check);

	if (check == 0) {
		printf("Initialize Success\n");
	}

	else {
		printf("Initialize Failure\n");
	}

	printf("Inserts up to 20 integers into the next available node\n");
	for (int y=0; y<=20; y++) {
		check = insert_buffer_421(y);
	}

	if (check == 0) {
                printf("Insert Success\n");
        }

        else {
                printf("Insert Failure\n");
	}

	check = print_buffer_421();

	if(check < 0) {
		printf("Print syscall failed\n");
	} else {
		printf("Print syscall ran successfully, check dmesg output\n");
	}

	check = delete_buffer_421();

	if(check < 0) {
                printf("Delete syscall failed\n");
        } else {
                printf("Delete syscall ran successfully\n");
        }

	return 0;
}
