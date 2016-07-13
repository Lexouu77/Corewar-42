# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 01:48:43 by ahamouda          #+#    #+#              #
#    Updated: 2016/06/23 20:14:27 by ahamouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
CC = clang
RM = rm -f
CFLAGS = -g -Wall -Werror -Wextra
OFLAGS = -O3 -march=native
DEBUGFLAG = -g3 -fsanitize=address
INCLUDES = ./libftprintf/
OBJ = $(SRC:.c=.o)
SRC = add.c\
	  and.c\
	  add_player.c\
	  aff.c\
	  check_bonus.c\
	  check_file_and_header.c\
	  check_instruction_from_proc.c\
	  check_period.c\
	  check_players_validity.c\
	  check_reg_number.c\
	  delete_invalid_players.c\
	  display_error.c\
	  display_field.c\
	  execute_instruction.c\
	  fork.c\
	  get_direct_arg_value.c\
	  get_number_of_players.c\
	  get_param_value.c\
	  get_players_id.c\
	  get_winner.c\
	  increment_waiting_time.c\
	  init_game.c\
	  init_process.c\
	  introduce_players.c\
	  kill_player.c\
	  live.c\
	  load.c\
	  long_fork.c\
	  new_player.c\
	  op.c\
	  or.c\
	  play.c\
	  set_last_player.c\
	  set_players_in_field.c\
	  set_players_number.c\
	  store.c\
	  store_index.c\
	  sub.c\
	  vm.c\
	  xor.c\
	  ncurses_vm.c\
	  zjump.c

HEADER = vm.h\
		 vm_struct.h\
		 op.h
LIB = ./libftprintf/libftprintf.a

NORMINETTE_TEST := $(shell norminette $(SRC) $(HEADER) | grep -B 1 Error)

#.SILENT:

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER) $(LIB)
	#make -C ./libftprintf
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) -I $(INCLUDES) -L ./libftprintf/ -lftprintf -lncurses
	#make -C ./libftprintf fclean

$(LIB) :
	make -C ./libftprintf/

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDES)

clean:
	$(RM) $(OBJ)
	make -C ./libftprintf/ clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libftprintf/ fclean

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
