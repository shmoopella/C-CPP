all: s21_math.a test

s21_math.a: s21_math.c s21_math.h
	gcc -Wall -Werror -Wextra -c s21_math.c
	ar rc s21_math.a s21_math.o
	cp s21_math.a libs21_math.a
	ranlib s21_math.a

clean:
	rm -rf *.o *.a a.out test.out math_check.c *.gcda *.gcno report *.info math_report

test: math.check
	checkmk clean_mode=1 math.check > math_check.c
	gcc -Wall -Werror -Wextra math_check.c s21_math.c -lcheck
	./a.out

gcov_report:
	checkmk clean_mode=1 math.check > math_check.c
	gcc -Wall -Werror -Wextra --coverage s21_math.c math_check.c  -o test.out -lcheck
	./test.out
	lcov -t "math_rep" -o math_rep.info -c -d .
	genhtml -o report math_rep.info
	open report/index.html