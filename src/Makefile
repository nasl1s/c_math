ifndef VERBOSE
.SILENT:
endif
CC = gcc
CC_FLAGS = -std=c11 -Wall -Wextra -Werror -g 
TEST_FLAGS = -std=c11 -g
GCOVFLAGS = -L. -ls21_math --coverage 
OS = $(shell uname)
CODE_STYLE=-style=Google

ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS = -lcheck `pkg-config --cflags --libs check`
endif

TEST_COMPILE = $(CC) $(TEST_FLAGS) libs21_math.a tests/s21_test.c $(CHECK_FLAGS) -L. -ls21_math

all: s21_math.a

rebuild: clean all

test: s21_math.a unittests
	$(TEST_COMPILE)
	./a.out

gcov_report: s21_math.a test
	rm -f *.g*
	$(CC) $(TEST_FLAGS) functions/s21*.c tests/s21_test.c libs21_math.a $(CHECK_FLAGS) $(GCOVFLAGS)
	./a.out
	lcov -t a.out -o rep.info -c -d .
	genhtml -o report rep.info
	open ./report/index.html
	rm -rf *.gcda *.gcno s21_tests s21_tests.info

s21_math.a: s21_math.o
	ar rcs libs21_math.a *.o
	rm -rf *.o
	ranlib libs21_math.a
	cp libs21_math.a s21_math.a
	cp libs21_math.a ls21_math.a

s21_math.o:
	$(CC) $(CC_FLAGS) -c functions/s21*.c

check: all unittests
	cppcheck --enable=all --suppress=missingIncludeSystem *.h functions/*.c tests/*.c
	clang-format -n *.h functions/*.c tests/*.c
ifeq ($(OS), Linux)
	$(CC) $(TEST_FLAGS) tests/s21_test.c tests/*.c libs21_math.a $(CHECK_FLAGS) -L. -ls21_math
	touch valgrind_res.txt
	valgrind --leak-check=full --log-file="valgrind_res.txt" --track-origins=yes --show-reachable=yes ./a.out
	grep "ERROR" valgrind_res.txt
endif

clean:
	rm -rf *.o *.g* *.info *.out report *.a *.dSYM debug valgrind_res.txt tests/*.log tests/*.xml tests/s21_test.c

include check.mk

.PHONY: _unittests.check