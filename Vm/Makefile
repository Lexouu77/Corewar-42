# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 01:48:43 by ahamouda          #+#    #+#              #
#    Updated: 2016/09/08 22:41:59 by ahamouda         ###   ########.fr        #
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
SRC = add.c\
	  add_player.c\
	  aff.c\
	  and.c\
	  assemble_asm_file.c\
	  check_asm_file.c\
	  check_file_header.c\
	  check_instruction_from_proc.c\
	  check_period.c\
	  check_players_validity.c\
	  check_reg_number.c\
	  create_new_player.c\
	  delete_invalid_players.c\
	  display_error.c\
	  display_field.c\
	  display_usage.c\
	  display_warning.c\
	  display_winner.c\
	  do_fork.c\
	  dump.c\
	  dump_and_wait.c\
	  execute_instruction.c\
	  fill_field.c\
	  free_arena.c\
	  get_instruction_parameter_size.c\
	  get_n_param_value.c\
	  get_n_param_size.c\
	  get_n_reg_param_value.c\
	  get_number_of_players.c\
	  get_param_value.c\
	  get_param_type.c\
	  get_parameter_size.c\
	  get_winner.c\
	  increment_waiting_time.c\
	  init_data.c\
	  init_game.c\
	  init_process.c\
	  introduce_players.c\
	  is_a_s_file.c\
	  is_file_valid.c\
	  is_someone_in_game.c\
	  kill_player.c\
	  manage_keys.c\
	  move_pc_from_format.c\
	  move_pc_without_format.c\
	  live.c\
	  load.c\
	  long_load.c\
	  load_index.c\
	  long_fork.c\
	  long_load_index.c\
	  op.c\
	  or.c\
	  parse_flag.c\
	  play.c\
	  vm.c\
	  set_color_field_owner.c\
	  set_last_player.c\
	  set_players_in_field.c\
	  set_players_in_game.c\
	  set_players_number.c\
	  stock_fixed_parameter_value.c\
	  stock_format.c\
	  stock_parameter_value.c\
	  stock_players_and_number.c\
	  stock_op_code.c\
	  store.c\
	  store_index.c\
	  sub.c\
	  xor.c\
	  write_param_value.c\
	  zjump.c

HEADER = op.h\
		 vm.h\
		 vm_struct.h


NORMINETTE_TEST := $(shell norminette $(SRC) $(HEADER) | grep -B 1 Error)

#.SILENT:

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER) $(LIB)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) -I $(INCLUDES) -L ./libftprintf/ -lftprintf -lcurses

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
