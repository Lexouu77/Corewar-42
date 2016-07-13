# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 01:48:43 by ahamouda          #+#    #+#              #
#    Updated: 2016/07/13 20:19:04 by ahamouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
CC = clang
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
OFLAGS = -O3 -march=native
DEBUGFLAG = -g3 -fsanitize=address
INCLUDES = ./
LIB = ./libftprintf/libftprintf.a
OBJ = $(SRC:.c=.o)
SRC = asm.c\
	  display_usage.c\
	  is_only_flags_or_nothing.c\
	  op.c
HEADER = asm.h\
		 op.h

NORMINETTE_TEST := $(shell norminette $(SRC) $(HEADER) | grep -B 1 Error)

.SILENT: norme

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER) $(LIB)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) -I $(INCLUDES) -L ./libftprintf/ -lftprintf

$(LIB) :
	make -C libftprintf

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDES)

clean:
	make -C libftprintf clean
	$(RM) $(OBJ)

fclean: clean
	make -C libftprintf fclean
	$(RM) $(NAME)

re: fclean all

norme:
ifeq ($(NORMINETTE_TEST), )
	@echo "Everything ok!"
else
	@norminette $(SRC) $(HEADER) | grep -B 1 Error
endif

watch:
	watch "make norme" "20"

function:
	nm -u $(NAME)

.PHONY: re fclean clean all norme watch function
