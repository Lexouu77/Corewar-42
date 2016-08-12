# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 01:48:43 by ahamouda          #+#    #+#              #
#    Updated: 2016/08/12 16:55:47 by ahamouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
CC = clang
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
OFLAGS = -O3 -march=native
DEBUGFLAG = -g3 -fsanitize=address
INCLUDES = ./
LIB = ./libftprintf/libftprintf.a
OBJ = $(SRC:.c=.o)
SRC = add_player.c\
	  check_file_header.c\
	  check_players_validity.c\
	  create_new_player.c\
	  delete_invalid_players.c\
	  display_error.c\
	  display_usage.c\
	  free_arena.c\
	  get_number_of_players.c\
	  get_winner.c\
	  init_data.c\
	  init_game.c\
	  init_process.c\
	  introduce_players.c\
	  is_file_valid.c\
	  op.c\
	  parse_flag.c\
	  vm.c\
	  set_players_number.c\
	  stock_players_and_number.c

HEADER = op.h\
		 vm.h\
		 vm_struct.c


NORMINETTE_TEST := $(shell norminette $(SRC) $(HEADER) | grep -B 1 Error)

#.SILENT:

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