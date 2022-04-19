#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>

#include "buffer_sem.h"

static bb_buffer_421_t buffer;
static sem_t mutex;
static sem_t fill_count;
static sem_t empty_count;

struct bb_node_421 *head = NULL;
struct bb_node_421 *current_now = NULL;
struct bb_node_421* tail = NULL;
struct bb_buffer_421 buffer_now;

long init_buffer_421(void) {
	// Write your code to initialize buffer
	struct bb_node_421* temp = malloc(sizeof(struct bb_node_421));

        int i = 0;

        // checks if buffer already been initialized
        if (head != NULL) {
                return -1;
        }

//      temp->data = char data[1024];
        temp->next = temp;

        // gets the head location
        head = temp;

        // tail location
        tail = temp;

        while (i<=18) {
                struct bb_node_421* newP = malloc(sizeof(struct bb_node_421));
//              newP -> data = 0;
                newP -> next = NULL;

                newP->next = tail->next;
                tail->next = newP;

                tail = tail->next;

                i++;
        }

        // Allows the read to start at head
        buffer.read = head;

        // gives the tail location to current for insert
        current_now = tail;

	// Initialize your semaphores here.
	sem_init(&mutex, 0, 1);
	
	return 0;
}


long enqueue_buffer_421(char * data) {
	// Write your code to enqueue data into the buffer
	if (buffer.write->data != 0) {
		printf("Buffer is full");
		return -1;
	}

	// check if head has been inserted
	if (head == NULL) {
		// stores the data into the buffer write
		strcpy(buffer.write->data, data);

		// increase the length of the buffer
		buffer_now.length++;
	}

	// moves the buffer write to the next node
	buffer.write = current_now->next;
	// moves the current position to the next node
	current_now = current_now->next;

	return 0;
}

long dequeue_buffer_421(char * data) {
	// Write your code to dequeue data from the buffer

	if (head == NULL) {
        	printf("Buffer is empty");
        	return -1;
    	}

    	// Check if this is the last node to be deleted
    	if (head == tail) {
        	data = head->data;
        	free(head);
        	head = NULL;
        	tail = NULL;
		current_now = NULL;
    	}
	// There are more than one nodes
    	else {
        	struct bb_node_421* temp = head;
        	data = temp->data;
        	head = head->next;
        	tail->next = head;
        	free(temp);
    	}

	return 0;
}


long delete_buffer_421(void) {
	// Tip: Don't call this while any process is waiting to enqueue or dequeue.
	// write your code to delete buffer and other unwanted components
	// if head is empty, then the delet will be unsuccessful
        if(head == NULL) {
                printf("Deleting the buffer unsuccessful\n");
                return -1;
        }

        // when the delete function is apply
        if(head != NULL) {
                // If head is not null create a temp node and current node pointed to next of head
                struct bb_node_421* temp;
                struct bb_node_421* curr;
                curr = head->next;

                // If current node is not equal to head, delete the current node and move current to next node using temp
                // Repeat the process till the current reaches the head
                while(curr != head) {
                        temp = curr->next;
                        free(curr);
                        curr = temp;
                }

                // Deleting the head
                free(head);
                head = NULL;

                printf("Deleting the Buffer successful\n");
        }

        buffer.length = 0;

	//sem_destroy(&mutex);
	//sem_destroy(&fill_count);
	//sem_destroy(&empty_count);

	return 0;
}


void print_semaphores(void) {
	// You can call this method to check the status of the semaphores.
	// Don't forget to initialize them first!
	// YOU DO NOT NEED TO IMPLEMENT THIS FOR KERNEL SPACE.
	int value;
	sem_getvalue(&mutex, &value);
	printf("sem_t mutex = %d\n", value);
	sem_getvalue(&fill_count, &value);
	printf("sem_t fill_count = %d\n", value);
	sem_getvalue(&empty_count, &value);
	printf("sem_t empty_count = %d\n", value);
	return;
}
