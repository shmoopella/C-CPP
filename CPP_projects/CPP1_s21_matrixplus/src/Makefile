all: clean s21_matrix_oop.a test 

s21_matrix_oop.a:
	g++ -Wall -Werror -Wextra -c s21_matrix_oop.cc
	ar rc libs21_matrix_oop.a s21_matrix_oop.o
	ranlib libs21_matrix_oop.a
	rm *.o

clean:
	rm -rf *.o *.a *.out

test:
	g++  -Wall -Werror -Wextra s21_matrix_oop.cc tests/tests_s21_matrix_oop.cc -lgtest -o test.out
	./test.out

leaks:
	g++  -Wall -Werror -Wextra s21_matrix_oop.cc tests/tests_s21_matrix_oop.cc -lgtest -o test.out
	leaks -atExit -- ./test.out

style:
	cp ../materials/linters/.clang-format .
	clang-format -n *.cc *.h