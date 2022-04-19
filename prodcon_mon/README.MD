CMSC-421-Project3

Name: Zachary Nguyen Campus ID: YS60130 Class Information: Section 02 CMSC 421 PRINCIPLES OF OPERATING SYSTEMS, Professor: Gerald Tompkins

I set up a function to solve producer-consumer problem using a circular buffer and Monitor in user space. Implement Monitor on a circular 
buffer using mutex and conditional variables with POSIX pthread API. I used Monitor for locking producer and consumer threads and their
print statements.

How to compile the user space:
gcc -c buffer_mon.c
gcc -c test_mon.c
gcc -Wall buffer_mon.c test_mon.c -o test
./test


The main difficulty I had was trying to inplement monitor instead of semaphore.
