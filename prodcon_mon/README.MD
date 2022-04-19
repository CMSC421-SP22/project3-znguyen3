CMSC-421-Project3

Name: Zachary Nguyen Campus ID: YS60130 Class Information: Section 02 CMSC 421 PRINCIPLES OF OPERATING SYSTEMS, Professor: Gerald Tompkins

This part is not completed. I would of set up a function to solve producer-consumer problem using a circular buffer and Monitor in user space. Implement 
Monitor on a circular buffer using mutex and conditional variables with POSIX pthread API. I used Monitor for locking producer and consumer threads and 
theirprint statements.

How to compile the user space:

gcc -c buffer_mon.c -lrt

gcc -c test_mon.c -lrt

gcc -Wall buffer_mon.c test_mon.c -o test -lpthread

./test

The main difficulty I had was trying to implement monitor instead of semaphore. It was due to the hard difficulties with part 2 that I did not reach much 
of part 3. I implement what I had for part two and replaced semaphores to monitor if I had more time to understand the concept of semaphores in C and how 
it would work in a circular buffer. The main results would have been similar to part 2 which shows that each function works when the function returns 0.
Knowing what makes part 2 works would help complete what I had done in part 3 to be more completed.
