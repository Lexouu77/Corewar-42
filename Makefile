# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjivas <adjivas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/13 17:56:53 by adjivas           #+#    #+#              #
#    Updated: 2016/09/13 18:39:20 by adjivas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

default: all

all:
	make -C Vm all
	make -C Asm all

clean:
	make -C Vm clean
	make -C Asm clean

fclean: clean
	make -C Vm fclean
	make -C Asm fclean

re: fclean
	make -C Vm re
	make -C Asm re
