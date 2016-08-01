/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 04:33:51 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 11:02:58 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		read_format(int fd, t_instruction *instr, int *i)
{
	int	j;

	instr->number_of_args = g_op_tab[instr->op_code - 1].arg_number;
	if (!g_op_tab[instr->op_code - 1].byte_param)
		return (1);
	j = -1;
	if (!read(fd, &instr->format, 1))
		return (0);
	*i = *i - 1;
	if (!(instr->parameter_type = (char*)malloc(sizeof(char)
			* instr->number_of_args)) || !(instr->parameter_value =
				(int*)malloc(sizeof(int) * instr->number_of_args)) ||
				!(instr->parameter_size =
			(int*)malloc(sizeof(int) * instr->number_of_args)))
		ft_malloc_error();
	read_param_types(instr);
	while (++j < instr->number_of_args)
		*i -= instr->parameter_size[j];
	return (1);
}
