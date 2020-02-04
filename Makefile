##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	=	bsq

SRC	=	src/main.c \
		src/print_square.c \
		src/map_to_array.c \
		src/get_map.c \

OBJ     =	$(SRC:.c=.o)

CFLAGS  +=	-Wall -Wextra -g3

CFLAGS  +=	-I./include

all     :	$(NAME)
		rm -f $(OBJ)

$(NAME) :	$(OBJ)
		@gcc -o $(NAME) $(OBJ)

clean	:
		rm -f $(OBJ)

fclean  :	clean
		rm -f $(NAME)

re      :	fclean all
		rm -f $(OBJ)

.SILENT	:	all fclean clean re

.PHONY	:	all fclean clean re
