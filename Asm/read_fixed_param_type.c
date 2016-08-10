/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fixed_param_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 04:34:30 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/10 22:42:52 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	max_size(void)
{
	int	i;

	i = 0;
	if (i < IND_SIZE)
		i = IND_SIZE;
	if (i < REG_SIZE)
		i = REG_SIZE;
	if (i < DIR_SIZE)
		i = DIR_SIZE;
	return (i);
}

int			read_fixed_param_types(int fd, t_instruction *instr, int *i)
{
	if (g_op_tab[instr->op_code - 1].byte_param)
		return (1);
	if (!(instr->parameter_type = (char*)malloc(sizeof(char)
			* instr->number_of_args)) || !(instr->parameter_value =
				(int*)malloc(sizeof(int) * instr->number_of_args)) ||
				!(instr->parameter_size =
			(int*)malloc(sizeof(int) * instr->number_of_args)))
		ft_malloc_error();
	instr->parameter_type[0] = 'd';
	instr->parameter_size[0] =
		(g_op_tab[instr->op_code - 1].byte_dir) ? IND_SIZE : DIR_SIZE;
	if (!read(fd, &instr->parameter_value[0], instr->parameter_size[0]))
		return (0);
	if (instr->parameter_size[0] <= 0 || instr->parameter_size[0] > max_size())
	{
		ft_printf_fd(2, "ERROR : Invalid parameter size.\n");
		exit(-1);
	}
	byte_swap(&instr->parameter_value[0], instr->parameter_size[0]);
	if (instr->parameter_size[0] == 2)
		instr->parameter_value[0] &= 0x0000FFFF;
	instr->size += instr->parameter_size[0];
	*i = *i - instr->parameter_size[0];
	instr->number_of_args = g_op_tab[instr->op_code - 1].arg_number;
	return (1);
}
