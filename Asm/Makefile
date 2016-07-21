# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 01:48:43 by ahamouda          #+#    #+#              #
#    Updated: 2016/07/22 00:59:09 by ahamouda         ###   ########.fr        #
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
SRC = add_file_content_line.c\
	  add_label_to_list.c\
	  asm.c\
	  assemble.c\
	  check_args.c\
	  check_comment.c\
	  check_forbidden_characters.c\
	  check_instructions.c\
	  check_instruction_label.c\
	  check_instruction_line.c\
	  check_instruction_parameters.c\
	  check_label_called.c\
	  check_name.c\
	  check_sign_error.c\
	  create_asm_file.c\
	  create_cor_file.c\
	  create_lst_instruction.c\
	  cut_comment_and_check_syntax.c\
	  cut_name_and_check_syntax.c\
	  delete_label_list.c\
	  disassemble.c\
	  display_comment_definition_error.c\
	  display_error.c\
	  display_error_line.c\
	  display_instruction_error.c\
	  display_label_call_error.c\
	  display_label_error.c\
	  display_name_definition_error.c\
	  display_usage.c\
	  display_success.c\
	  does_instruction_exist.c\
	  free_file_content.c\
	  free_list.c\
	  get_asm_body.c\
	  get_parameter_define_type.c\
	  get_number_of_arg.c\
	  get_shorten_len.c\
	  go_to_next_label_call.c\
	  go_to_next_param.c\
	  has_a_label_call.c\
	  is_a_cor_file.c\
	  is_a_s_file.c\
	  is_file_valid.c\
	  is_instruction_label.c\
	  is_label_called.c\
	  is_only_flags_or_nothing.c\
	  label_already_exist.c\
	  line_has_comment.c\
	  line_starts_with_comment.c\
	  op.c\
	  read_fixed_param_type.c\
	  read_format.c\
	  read_op_code.c\
	  read_param_type.c\
	  read_param_value.c\
	  remove_comment_from_file_content.c\
	  remove_comment_from_line.c\
	  remove_name_from_file_content.c\
	  reset_data_struct.c\
	  stock_comment.c\
	  stock_file_content.c\
	  stock_name.c\
	  was_already_called.c\
	  write_asm_body.c\
	  write_asm_header.c\
	  write_asm_param.c\
	  write_cor_header.c
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
