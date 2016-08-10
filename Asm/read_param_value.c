/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_param_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 04:34:08 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/10 22:43:12 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_max_size(void)
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

int			read_param_value(int fd, t_instruction *instr)
{
	int			i;

	i = -1;
	if (!g_op_tab[instr->op_code - 1].byte_param)
		return (1);
	while (++i < instr->number_of_args)
	{
		if (instr->parameter_size[i] <= 0 || instr->parameter_size[i] >
				get_max_size())
		{
			ft_printf_fd(2, "ERROR : Invalid parameter size.\n");
			exit(-1);
		}
		if (!read(fd, &instr->parameter_value[i], instr->parameter_size[i]))
			return (0);
		byte_swap(&instr->parameter_value[i], instr->parameter_size[i]);
		if (instr->parameter_size[i] == 2)
			instr->parameter_value[i] &= 0x0000FFFF;
	}
	return (1);
}
