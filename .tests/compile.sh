make -C ../
gcc -g -I ../ tests.c -lbsd -o run_test.out ../libft.a
