make -C ../
gcc -g -I ../include/ ../src/ft_*.c tests.c -lbsd -o run_test.out
