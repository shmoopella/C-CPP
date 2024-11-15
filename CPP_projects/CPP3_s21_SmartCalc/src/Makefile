OS = $(shell uname)
GCC=g++ -std=c++17 -Wall -Werror -Wextra
LIBFLAGS = -lm -lgtest -lstdc++
TEST = tests/tests_s21_calc.cc
MODEL = Calculator/Model/calculator_model.cc
CHECKFILES = Calculator/Controller/*.h \
	Calculator/Model/*.h \
	Calculator/Model/*.cc \
	Calculator/View/*.cc \
	Calculator/View/*.h \
	tests/*.cc

all: clean tests

tests: clean
	$(GCC) $(TEST) $(MODEL) $(LIBFLAGS) -o test
	./test
clean:
	rm -rf test build *.o Archive_SmartCalc_v2.0 *.txt dvi.aux dvi.log dvi.out dvi.dvi Calculator/SmartCalc.pro.user

install:
	make clean
	mkdir build
	cd build && qmake ../Calculator/SmartCalc.pro && make
	cd build && rm -rf *.o *.cpp *.h .qmake.stash

uninstall:
	rm -rf build

dvi:
	texi2dvi dvi.tex

dist:
	mkdir Archive_SmartCalc_v2.0/
	tar -zcf Archive_SmartCalc_v2.0/Archive_SmartCalc_v2.0.tgz Calculator Makefile tests/ dvi.tex

style:
	clang-format -style=Google -n $(CHECKFILES)

leaks: tests

ifeq ($(OS), Darwin)
	leaks --atExit -- ./test
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./test
endif
