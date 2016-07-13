# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 01:48:43 by ahamouda          #+#    #+#              #
#    Updated: 2016/07/12 15:18:15 by ahamouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
CC = clang
RM = rm -f
CFLAGS = -g -Wall -Werror -Wextra
OFLAGS = -O3 -march=native
DEBUGFLAG = -g3 -fsanitize=address
INCLUDES = ./libftprintf/
OBJ = $(SRC:.c=.o)
SRC = asm.c\
	  check_bonus_flags.c\
	  check_file_name.c\
	  check_line_error.c\
	  create_file.c\
	  create_lst_instruction.c\
	  create_lst_label.c\
	  disassemble.c\
	  display_bonus.c\
	  epur_str.c \
	  error_messages.c\
	  get_instruction.c\
	  get_body.c\
	  get_op_code.c\
	  go_to_next_parameter.c\
	  is_a_cor_file.c\
	  loop_label_instructions.c\
	  op.c\
	  parse_comment.c\
	  parse_name.c\
	  push_lst_instruction.c\
	  push_lst_label.c \
	  stock_instructions.c\
	  stock_label_called.c\
	  stock_size_to_label.c\
	  usage.c\
	  write_body.c

HEADER = asm.h\
		 op.h
LIB = ./libftprintf/libftprintf.a

NORMINETTE_TEST := $(shell norminette $(SRC) $(HEADER) | grep -B 1 Error)

.SILENT: norme

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER) $(LIB)
	#make -C ./libftprintf
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) -I $(INCLUDES) -L ./libftprintf/ -lftprintf
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
	echo "Everything ok!"
else
	norminette $(SRC) $(HEADER) | grep -B 1 Error
endif

watch:
	watch "make norme" "20"

function:
	nm -u $(NAME)

.PHONY: re fclean clean all norme watch function
