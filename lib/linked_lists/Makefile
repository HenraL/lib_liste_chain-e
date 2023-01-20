##
## EPITECH PROJECT, 2022
## B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
## File description:
## Makefile
##

DEP_DIR	=	sub_dependencies/

SRC	=	pop.c	\
		get_node.c	\
		free_list.c	\
		init_list.c	\
		append_node.c	\
		display_node.c	\
		display_list.c	\
		get_node_data.c	\
		get_node_type.c	\
		update_indexes.c	\

DEP_SRC	=	$(DEP_DIR)ll_putstr.c	\
			$(DEP_DIR)ll_strlen.c	\
			$(DEP_DIR)ll_putchar.c	\
			$(DEP_DIR)ll_put_nbr.c	\
			$(DEP_DIR)ll_put_str_nb.c	\
			$(DEP_DIR)ll_put_str_str.c	\

SILENT	=	@

CC	=	$(SILENT)gcc

RM	=	$(SILENT)rm -f

COPY	=	$(SILENT)cp

CPPFLAGS	=	-I../../include

CFLAGS	=	-Wall -Wextra -lm

HEADERFILE	=	linked_lists.h

PROG_SRC	=	$(SRC)
PROG_SRC	+=	$(DEP_SRC)

PROG_OBJ	=	$(PROG_SRC:.c=.o)

NAME	=	liblinklist.a

DYNAMIC	=	$(patsubst %.a,%.so,$(NAME))

all: update_includes $(NAME) update_archive

$(NAME):	$(PROG_OBJ)
	$(SILENT)ar rc $(NAME) $(PROG_OBJ)

update_archive:
	$(COPY) $(NAME) ../

update_dynamic_archive:
	$(COPY) $(DYNAMIC) ../

update_includes:
	$(COPY) $(HEADERFILE) ../../include

shared:	$(DYNAMIC) update_includes update_dynamic_archive

$(DYNAMIC):	$(PROG_OBJ)
	$(CC) -shared -o $(DYNAMIC) $(PROG_OBJ)

all_types:	all	shared

clean:
	$(RM) $(PROG_OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(DYNAMIC)
	$(RM) ../$(NAME)
	$(RM) ../$(DYNAMIC)

re:	fclean	all

re_share:	fclean	shared

re_all:	fclean	all	shared

.PHONY:	all	shared	all_types	\
		update_archive	update_dynamic_archive	\
		clean	fclean	\
		re	re_share	re_all
