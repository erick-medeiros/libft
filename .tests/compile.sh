make -C ../
gcc -g -I ../include/ tests.c -lbsd -o run_test.out ../libft.a
