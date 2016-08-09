/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_param_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 04:41:32 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/09 18:00:11 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		read_param_types(t_instruction *instr)
{
	int	i;
	int	shift;

	i = -1;
	if (instr->number_of_args < 0 || instr->number_of_args > 5)
		return ;
	while (++i < instr->number_of_args)
	{
		shift = 6 - 2 * i;
		if (((instr->format >> shift) & 0x3) == REG_CODE)
			instr->parameter_type[i] = 'r';
		else if (((instr->format >> shift) & 0x3) == IND_CODE)
			instr->parameter_type[i] = 'i';
		else if (((instr->format >> shift) & 0x3) == DIR_CODE)
			instr->parameter_type[i] = 'd';
		if (instr->parameter_type[i] == 'r')
			instr->parameter_size[i] = 1;
		else if (instr->parameter_type[i] == 'i')
			instr->parameter_size[i] = IND_SIZE;
		else if (instr->parameter_type[i] == 'd')
			instr->parameter_size[i] =
				(g_op_tab[instr->op_code - 1].byte_dir) ? IND_SIZE : DIR_SIZE;
		instr->size += instr->parameter_size[i];
	}
}
