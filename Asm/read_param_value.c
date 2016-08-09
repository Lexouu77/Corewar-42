/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_param_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 04:34:08 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/09 18:02:53 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		read_param_value(int fd, t_instruction *instr)
{
	int			i;

	i = -1;
	if (!g_op_tab[instr->op_code - 1].byte_param)
		return (1);
	while (++i < instr->number_of_args)
	{
		if (!read(fd, &instr->parameter_value[i], instr->parameter_size[i]))
			return (0);
		byte_swap(&instr->parameter_value[i], instr->parameter_size[i]);
		if (instr->parameter_size[i] == 2)
			instr->parameter_value[i] &= 0x0000FFFF;
	}
	return (1);
}
