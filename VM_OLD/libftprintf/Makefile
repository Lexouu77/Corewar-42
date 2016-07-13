# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 01:48:30 by ahamouda          #+#    #+#              #
#    Updated: 2016/06/06 22:55:36 by ahamouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
OFLAGS = -O3 -march=native
DEBUGFLAG = -g3 -fsanitize=address
INCLUDES = ./
OBJ = $(SRC:.c=.o)
SRC = ft_printf.c\
	  ft_printf_fd.c\
	  apply_bg.c\
	  apply_fg.c\
	  apply_spe.c\
	  bufferjoin.c\
	  bufferujoin.c\
	  byte_swap.c\
	  cast_normal_integer.c\
	  check_parsing.c\
	  display.c\
	  display_var.c\
	  get_ansi_code.c\
	  get_flags.c\
	  get_nb_min_char.c\
	  get_sign.c\
	  get_sub_specifier.c\
	  get_type.c\
	  get_unicode_len.c\
	  get_spe_flags.c\
	  init_t_flag.c\
	  itoa_base.c\
	  parsing.c\
	  print_binary.c\
	  print_char.c\
	  print_int_tab.c\
	  print_normal_char.c\
	  print_normal_integer.c\
	  print_pointer.c\
	  print_str_tab.c\
	  print_unicode_char.c\
	  print_unicode_string.c\
	  printf_normal_string.c\
	  reset_tab.c\
	  stock_n.c\
	  uc_to_str.c\
	  ft_atoi.c\
	  ft_bzero.c\
	  ft_error.c\
	  ft_fctrl.c\
	  ft_is_str_digit.c\
	  ft_is_str_space.c\
	  ft_isalnum.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isblank.c\
	  ft_iscntrl.c\
	  ft_isgraph.c\
	  ft_islower.c\
	  ft_isprint.c\
	  ft_ispunct.c\
	  ft_isupper.c\
	  ft_isxdigit.c\
	  ft_isdigit.c\
	  ft_isspace.c\
	  ft_itoa.c\
	  ft_lstadd.c\
	  ft_lstcswap.c\
	  ft_lstdel.c\
	  ft_lstdelone.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_lstpush.c\
	  ft_lstnew.c\
	  ft_malloc_error.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memmove.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memdel.c\
	  ft_memset.c\
	  ft_putendl.c\
	  ft_putstr.c\
	  ft_screenclr.c\
	  ft_sqrt.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strclr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdel.c\
	  ft_strequ.c\
	  ft_strdup.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strjoinsep.c\
	  ft_strjoinsep_and_free.c\
	  ft_strjoin_and_free.c\
	  ft_strlcat.c\
	  ft_strlen.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strmchr.c\
	  ft_strmrepl.c\
	  ft_strncat.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strndup.c\
	  ft_strnequ.c\
	  ft_strnew.c\
	  ft_strnmchr.c\
	  ft_strrchr.c\
	  ft_strrepl.c\
	  ft_strrev.c\
	  ft_strsplit.c\
	  ft_strnstr.c\
	  ft_strstr.c\
	  ft_strsub.c\
	  ft_strtrim.c\
	  ft_strxcmp.c\
	  ft_strxlen.c\
	  ft_strxdup.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  get_next_line.c\
	  ftprintf_strjoin.c\
	  ftprintf_strncpy_cat.c\
	  ftprintf_strndup.c
HEADER = ft_printf.h

#.SILENT:

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDES)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

function:
	nm -u $(NAME)

.PHONY: re fclean clean all norme watch function
