CC=gcc
CFLAGS=-c -Wall -Werror -Wextra -std=c11
CTESTFLAGS=-lcheck --coverage

SOURCES=s21_tan.c s21_cos.c s21_sin.c s21_atan.c \
s21_acos.c s21_asin.c s21_exp.c s21_log.c \
s21_abs.c s21_ceil.c s21_fabs.c s21_floor.c \
s21_fmod.c s21_pow.c s21_sqrt.c s21_helpers.c

HELPERS=s21_helpers.c

OBJECTS=$(addprefix temp/,$(SOURCES:.c=.o))

OS := $(shell uname -s)
ifeq ($(OS), Darwin)
	FLAGS += -D OS_MAC
else
	FLAGS += -D OS_LINUX
		CTESTFLAGS += -lpthread -pthread -lrt -lm -lsubunit
endif

all: clean s21_math.a

clean:
	rm -rf temp/*
	rm -rf *.o *.out *.a *.gcda *.gcno *.gcov
	rm -rf s21_math_test.c
	rm -rf clang-format

test: fromcheck
	$(CC) $(FLAGS) $(SOURCES) s21_math_test.c $(CTESTFLAGS) -g -o temp/s21_test
	temp/s21_test
	
valgrind_test: obj
	$(CC) $(FLAGS) $(SOURCES) s21_math_test.c $(CTESTFLAGS) -g -O0 -o temp/s21_test_v
	valgrind --leak-check=full --quiet temp/s21_test_v

s21_math.a: obj
	ar rcs s21_math.a $(OBJECTS) temp/s21_helpers.o
	ranlib s21_math.a

gcov_report:
	gcovr
	gcovr --html-details coverage.html
	mv *.html temp/
	mv *.css temp/

style_check:
	cp ../materials/linters/clang-format clang-format
	clang-format -n *.c *.h
	
fromcheck:
	checkmk s21_math_test.check > s21_math_test.c

obj:
	$(CC) $(CFLAGS) $(SOURCES)
	mv *.o temp/
