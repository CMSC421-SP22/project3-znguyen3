#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"

struct node_421 *head = NULL;
struct node_421 *current = NULL;
struct node_421* tail = NULL;

long init_buffer_421(void) {
	struct node_421* temp = malloc(sizeof(struct node_421));
        static ring_buffer_421_t buffer;

	int i = 0;

	// checks if buffer already been initialized
        if (head != NULL) {
                return -1;
        }

	temp->data = 0;
	temp->next = temp;

	// gets the head location
	head = temp;

	// tail location
	tail = temp;

	while (i<=18) {
		struct node_421* newP = malloc(sizeof(struct node_421));
		newP -> data = 0;
		newP -> next = NULL;

		newP->next = tail->next;
		tail->next = newP;

		tail = tail->next;

		i++;
	}

	// Allows the read to start at head
	buffer.read = head;

	// gives the tail location to current for insert
	current = tail;

//	printf("Length: %d\n", count->length);
	return 0;
}


long insert_buffer_421(int i) {
//	struct ring_buffer_421* count = malloc(sizeof(struct ring_buffer_421));
	static ring_buffer_421_t buffer;

	//Inserting fails if the buffer is already full.
	if (current->next->data != 0) {
		printf("Buffer is full\n");
		return -1;
	}

	if (head->data == 0){
		head->data = i;
		buffer.length += 1;

		current = tail->next;
	}

	else {
		//Inserts the integer i into the next available node
		current->next->data = i;

		//Increment the buffer length when you insert.
		buffer.length += 1;

		// Move current down the buffer circle
		current = current->next;
	}

	return 0;

}


long print_buffer_421() {
	static ring_buffer_421_t buffer;

	// The index of each node
	int count = 0;

	buffer.read = tail->next;

	if (tail == NULL) {
                printf("Cannot print an uninitialized buffer\n");
                return -1;
        }

        else {
                struct node_421* p = buffer.read;
                do
                {
			fprintf(stdout, "Node: %d, Data: %d\n",count,p->data);
                        p = p->next;
			count++;

                } while(p != buffer.read);
        }

	printf("\n");

	return 0;
}


long delete_buffer_421() {
	static ring_buffer_421_t buffer;

	if(head == NULL) {
		printf("Deleting the buffer unsuccessful\n");
		return -1;
	}

	if(head != NULL) {
    		// If head is not null create a temp node and current node pointed to next of head
    		struct node_421* temp;
    		struct node_421* curr;
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

	return 0;
}
