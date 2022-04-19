CMSC-421-Project3

Name: Zachary Nguyen Campus ID: YS60130 Class Information: Section 02 CMSC 421 PRINCIPLES OF OPERATING SYSTEMS, Professor: Gerald Tompkins

I set up multiple functions to create a circular buffer in user space and kernel space. I first start by initializing every node and then filling the 
buffer with integers and printing the buffer's contents to the stdout/kernel log depending on which space. And lastly, deleting the buffer and free any 
allocated memory. I created a circular buffer that comprises a singly linked list consisting of twenty nodes, each holding an integer and a pointer to 
the next node, forming a circular structure.

How to compile user space:

gcc -c test_user.c 

gcc -c buffer_user.c

gcc -Wall buffer_user.c test_user.c -o test

./test

How to compile kernel space:

gcc test.c -o testk

./testk

Afterwards, once the kernel compiles, check the dmesg output by running the following command:

sudo dmesg

The results should show that the initialization of 20 nodes is successful and then being inserted with data value increasing by 1 and starting
at 1 with a success message. It will show a string representation of every node in the buffer, with 20 in total, starting from 0. 
Along with the data in each node, an increasing value starts from 1 for each node, beginning at the buffer's read pointer.

The main difficulty I had with working on the user-space is getting the circular buffer to work and getting the insert to insert the integer into the next 
available node. While the kernel, the most I had problems with is getting to know how to migrate the source code into the kernel correctly and having
problems keep on popping up. Another problem that I had while working on the kernel is when I did not get the right value for the insert function, before 
realizing that I needed to fix the parameters inside the function in test.c. The difference between user and kernel space is how some user-space source 
code does not apply in the kernel like the "for" loop and free being kfree in the kernel. I had the most trouble with compiling the custom Linux kernel due 
to taking a large amount of time waiting and hoping that it compiles after making adjustments to the buffer.c when I not getting the right results.
