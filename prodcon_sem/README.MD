CMSC-421-Project3

Name: Zachary Nguyen Campus ID: YS60130 Class Information: Section 02 CMSC 421 PRINCIPLES OF OPERATING SYSTEMS, Professor: Gerald Tompkins

I tried to set up the circular buffer with a producer that inserts data into the buffer and a consumer that will then take 
each entry out of the buffer and display the characters to the screen.

How to compile the user space:
gcc -c buffer_user_sem.c -lrt
gcc -c test_user_sem.c -lrt
gcc -Wall buffer_user_sem.c test_user_sem.c -o test -lpthread
./test

How to complie the kernel space:
gcc test_sem.c -o testk
./testk

The most challening part was figuring out how to start with the semaphores with initalizing the locks. Another issue 
that keep on popping up was the sleep function bot working as intended. The consumer and producer was hard to initalize into
c and getting it right to get enqueue and dequeue to work correctly. I have not fully finished the kernel nor the user space
code as I was getting problems left and right with the semaphones to work correctly. I did add the systems calls to be
added to syscalls.h.
