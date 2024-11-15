all: clean s21_matrix.a test 

s21_matrix.a:
	gcc -Wall -Werror -Wextra -c s21_matrix.c
	ar rc s21_matrix.a s21_matrix.o
	ranlib s21_matrix.a
	cp s21_matrix.a libs21_matrix.a
	rm *.o

clean:
	rm -rf *.o *.a test.out *.gcda *.gcno *.info report matrix_report matrix_test.c

test:
	checkmk clean_mode=1 matrix.check > matrix_test.c
	gcc -Wall -Werror -Wextra matrix_test.c s21_matrix.c -lcheck -o test.out
	./test.out

gcov_report:
	checkmk clean_mode=1 matrix.check > matrix_test.c
	gcc --coverage -Wall -Werror -Wextra matrix_test.c s21_matrix.c -lcheck -o matrix_report
	./matrix_report
	lcov -t "matrix_rep" -o matrix_rep.info -c -d .
	genhtml -o report matrix_rep.info
	open report/index.html