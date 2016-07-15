/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fixed_param_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 04:34:30 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/15 09:31:21 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		read_fixed_param_types(int fd, t_instruction *instr, int *i)
{
	if (g_op_tab[instr->op_code - 1].byte_param)
		return (1);
	if (!(instr->args_type = (char*)malloc(sizeof(char)
			* instr->number_of_args)) || !(instr->args_value =
				(int*)malloc(sizeof(int) * instr->number_of_args)) ||
				!(instr->args_byte_size =
			(int*)malloc(sizeof(int) * instr->number_of_args)))
		ft_malloc_error();
	instr->args_type[0] = 'd';
	instr->args_byte_size[0] =
		(g_op_tab[instr->op_code - 1].byte_dir) ? IND_SIZE : DIR_SIZE;
	if (!read(fd, &instr->args_value[0], instr->args_byte_size[0]))
		return (0);
	byte_swap(&instr->args_value[0], instr->args_byte_size[0]);
	if (instr->args_byte_size[0] == 2)
		instr->args_value[0] &= 0x0000FFFF;
	instr->bytes_size += instr->args_byte_size[0];
	*i = *i - instr->args_byte_size[0];
	instr->number_of_args = g_op_tab[instr->op_code - 1].arg_number;
	return (1);
}
