#include "buffer.h"
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/slab.h>

struct node_421 *head = NULL;
struct node_421 *current_now = NULL;
struct node_421* tail = NULL;
struct ring_buffer_421 buffer;

SYSCALL_DEFINE0(init_buffer_421) {
	struct node_421* temp = kmalloc(sizeof(struct node_421), GFP_KERNEL);

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
                struct node_421* newP = kmalloc(sizeof(struct node_421), GFP_KERNEL);
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
        current_now = tail;

        return 0;
}

SYSCALL_DEFINE1(insert_buffer_421,int,i) {
        //Inserting fails if the buffer is already full.
        if (current_now->next->data != 0) {
                printk("Buffer is full\n");
                return -1;
        }

        if (head->data == 0){
                head->data = i;
                buffer.length += 1;

                current_now = tail->next;
        }

        else {
                //Inserts the integer i into the next available node
                current_now->next->data = i;

                //Increment the buffer length when you insert.
                buffer.length += 1;

                // Move current down the buffer circle
                current_now = current_now->next;
        }

        return 0;
}

SYSCALL_DEFINE0(print_buffer_421) {
        // The index of each node
        int count = 0;

        buffer.read = tail->next;

        if (tail == NULL) {
                printk("Cannot print an uninitialized buffer\n");
                return -1;
        }

        else {
                struct node_421* p = buffer.read;
                do
                {
                        printk("Node: %d, Data: %d\n",count,p->data);
                        p = p->next;
                        count++;

                } while(p != buffer.read);
        }

        printk("\n");

        return 0;
}

SYSCALL_DEFINE0(delete_buffer_421) {
	// if head is empty, then the delet will be unsuccessful
        if(head == NULL) {
                printk("Deleting the buffer unsuccessful\n");
                return -1;
        }

	// when the delete function is apply
        if(head != NULL) {
                // If head is not null create a temp node and current node pointed to next of head
                struct node_421* temp;
                struct node_421* curr;
                curr = head->next;

                // If current node is not equal to head, delete the current node and move current to next node using temp
                // Repeat the process till the current reaches the head
                while(curr != head) {
                        temp = curr->next;
                        kfree(curr);
                        curr = temp;
                }

                // Deleting the head
                kfree(head);
                head = NULL;

                printk("Deleting the Buffer successful\n");
        }

        buffer.length = 0;

        return 0;
}
