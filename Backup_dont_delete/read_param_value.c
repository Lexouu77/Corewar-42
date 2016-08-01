/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_param_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 04:34:08 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/15 09:33:24 by ahamouda         ###   ########.fr       */
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
		if (!read(fd, &instr->args_value[i], instr->args_byte_size[i]))
			return (0);
		byte_swap(&instr->args_value[i], instr->args_byte_size[i]);
		if (instr->args_byte_size[i] == 2)
			instr->args_value[i] &= 0x0000FFFF;
	}
	return (1);
}
