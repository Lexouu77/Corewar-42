# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+         #
#        adjivas <adjivas@student.42.fr>          +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 01:48:43 by ahamouda          #+#    #+#              #
#    Updated: 2016/09/11 22:59:20 by adjivas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(CC),gcc)
	LDFLAGS := -Wl,--gc-sections
endif

NAME = corewar
DIRC := src
FLAG := $(LDFLAGS) -Wall -Wextra -Werror -O3
SRCA := ./libftprintf/libftprintf.a
SRCA += ./libcoretermion/libcoretermion.a
INDS := -I./inc -I./libftprintf
SRCS := add.c
SRCS += add_player.c
SRCS += aff.c
SRCS += and.c
SRCS += assemble_asm_file.c
SRCS += check_asm_file.c
SRCS += check_file_header.c
SRCS += check_instruction_from_proc.c
SRCS += check_period.c
SRCS += check_players_validity.c
SRCS += check_reg_number.c
SRCS += create_new_player.c
SRCS += delete_invalid_players.c
SRCS += display_error.c
SRCS += display_field.c
SRCS += display_usage.c
SRCS += display_warning.c
SRCS += display_winner.c
SRCS += do_fork.c
SRCS += dump.c
SRCS += dump_and_wait.c
SRCS += execute_instruction.c
SRCS += fill_field.c
SRCS += free_arena.c
SRCS += get_instruction_parameter_size.c
SRCS += get_n_param_size.c
SRCS += get_n_param_value.c
SRCS += get_n_reg_param_value.c
SRCS += get_number_of_players.c
SRCS += get_param_type.c
SRCS += get_param_value.c
SRCS += get_parameter_size.c
SRCS += get_winner.c
SRCS += increment_waiting_time.c
SRCS += init_data.c
SRCS += init_game.c
SRCS += init_process.c
SRCS += introduce_players.c
SRCS += is_a_s_file.c
SRCS += is_file_valid.c
SRCS += is_someone_in_game.c
SRCS += kill_player.c
SRCS += live.c
SRCS += load.c
SRCS += load_index.c
SRCS += long_fork.c
SRCS += long_load.c
SRCS += long_load_index.c
SRCS += move_pc_from_format.c
SRCS += move_pc_without_format.c
SRCS += op.c
SRCS += or.c
SRCS += parse_flag.c
SRCS += play.c
SRCS += set_color_field_owner.c
SRCS += set_last_player.c
SRCS += set_players_in_field.c
SRCS += set_players_in_game.c
SRCS += set_players_number.c
SRCS += stock_fixed_parameter_value.c
SRCS += stock_format.c
SRCS += stock_op_code.c
SRCS += stock_parameter_value.c
SRCS += stock_players_and_number.c
SRCS += store.c
SRCS += store_index.c
SRCS += sub.c
SRCS += vm.c
SRCS += write_param_value.c
SRCS += xor.c
SRCS += zjump.c
LSTC := $(patsubst %,$(DIRC)/%,$(SRCS))
OBJO := $(LSTC:.c=.o)

.PHONY: default version all clean fclean re example
.SILENT: clean fclean version example

default: all

version:
	$(CC) --version

all: $(NAME)

$(NAME): $(OBJO)
	make -C libcoretermion
	make -C libftprintf
	$(CC) $(FLAG) $^ -o $@ $(SRCA) -framework OpenAL

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@ $(INDS)

clean:
	make -C libcoretermion clean
	make -C libftprintf clean
	/bin/rm -rfv $(OBJO)

fclean:
	make -C libcoretermion fclean
	make -C libftprintf fclean
	/bin/rm -rfv $(OBJO)
	/bin/rm -rfv $(NAME)

re:
	/bin/rm -rfv $(OBJO)
	/bin/rm -rfv $(NAME)
	make -C libcoretermion
	make -C libftprintf
	make -C .
