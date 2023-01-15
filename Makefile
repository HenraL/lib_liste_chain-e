##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## jitter jitter
##

SRC	=	./src/hl_strlen.c	\
		./src/hl_putstr.c	\
		./src/hl_put_nbr.c	\

OBJ	=	$(SRC:.c=.o)

SILENT	=	@

CC	=	$(SILENT)gcc

MAK	=	$(SILENT)make -C

RM	=	$(SILENT)rm	-f

MAIN	=	main.c

OBJ_MAIN	=	$(MAIN:.c=.o)

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include

NAME	=	your_test

LIB	=	-L lib/linked_lists -llinklist

UNIT_FILE   =   ./tests/test_linked_lists.c

UNIT_FLAG   =   --coverage -lcriterion

UNIT_NAME	=	unit_tests

all:	$(NAME)

$(NAME):	compile_libs $(OBJ) $(OBJ_MAIN)
	$(CC) -o $(NAME) $(OBJ_MAIN) $(OBJ) $(CPPFLAGS) $(LIB)

compile_libs:
	$(MAK) lib/linked_lists

debug:	CFLAGS	+=	-g3
debug:	NAME	+=	_debug
debug:	all

for_unit_testing: compile_libs update_dep $(PROG_OBJ)
	$(CC) -o $(UNIT_NAME) $(PROG_OBJ) $(UNIT_FILE) $(LIB) $(UNIT_FLAG)

clean_libs:
	$(MAK) lib/linked_lists clean

clean_test: clean_libs
	$(RM) *.gcda
	$(RM) *.gcno

clean: clean_libs
	$(RM) $(OBJ)

fclean_libs:
	$(MAK) lib/linked_lists fclean

fclean_test: clean_test fclean_libs
	$(RM) $(UNIT_NAME)

fclean: clean fclean_libs
	$(RM) $(NAME)

run_tests:
	$(SILENT)./$(UNIT_NAME)

unit_tests: fclean_test for_unit_testing

test_run: unit_tests run_tests

tests_run: unit_tests run_tests

test_coverage: tests_run
	$(SILENT)gcovr . --exclude tests/ --branches

recov: fclean test_coverage

retest: fclean_test fclean tests_run

re: fclean all clean

.PHONY: all unit_tests compile_libs debug for_unit_testing \
clean clean_libs clean_test \
fclean fclean_libs fclean_test \
run_tests test_run tests_run test_coverage \
re recov retest
