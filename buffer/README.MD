gcc -c test_user.c 
ggc -c buffer_user.c
gcc -Wall buffer_user.c test_user.c -o test
./test
