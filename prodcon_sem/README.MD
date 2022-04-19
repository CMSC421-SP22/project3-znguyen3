CMSC-421-Project3

Name: Zachary Nguyen Campus ID: YS60130 Class Information: Section 02 CMSC 421 PRINCIPLES OF OPERATING SYSTEMS, Professor: Gerald Tompkins

I tried to set up the circular buffer with a producer that inserts data into the buffer and a consumer that will then take 
each entry out of the buffer and display the characters on the screen. This solves the Bounded Buffer problem / producer-consumer and 
implements a set of system calls to provide a circular buffer available to concurrent consumer and producer threads in kernel space. I created
a for loop to iterate 1000 times and used the rand() function to put random amounts of time between each iteration. With this, enqueue or dequeue a
block containing 1024 char bytes into the circular buffer with both the producer and consumer executing concurrently.

How to compile the user space:

gcc -c buffer_user_sem.c -lrt

gcc -c test_user_sem.c -lrt

gcc -Wall buffer_user_sem.c test_user_sem.c -o test -lpthread

./test

How to complie the kernel space:
gcc test_sem.c -o testk
./testk

The most challenging part was figuring out how to start with the semaphores with initializing the locks. Another issue 
that keep on popping up was the sleep function not working as intended. The consumer and producer were hard to initialize into
c and get it right to get so that enqueue and dequeue function would work correctly. I have not fully finished the kernel nor the user space
code as I was getting problems left and right with the semaphore working correctly. I would have added the systems calls to be
added to syscalls.h as one of the requirements was suggested but I couldn't do it as it would have messed up part one kernel compiling due to
part 2 not being fully completed. I have commented out the required code that would have added the syscalls and removed the proncon_sem from the kernel
makefile to not mess up part 1.
