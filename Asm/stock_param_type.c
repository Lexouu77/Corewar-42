/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_param_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 09:39:50 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 10:29:13 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	stock_param_type(t_instruction *instruction, char *s, int shift)
{
	const int	index = ((6 - shift) / 2);

	if (*s && *s == 'r')
		instruction->parameter_type[index] = 'r';
	else if (*s && s[1] && *s == DIRECT_CHAR && s[1] == LABEL_CHAR)
	{
		instruction->parameter_type[index] = 'l';
		instruction->number_of_label_called++;
	}
	else if (*s && *s == DIRECT_CHAR)
		instruction->parameter_type[index] = 'd';
	else
		instruction->parameter_type[index] = 'i';
	if (instruction->parameter_type[index] == 'r')
		instruction->size++;
	if (instruction->parameter_type[index] == 'l')
		instruction->size += IND_SIZE;
	if (instruction->parameter_type[index] == 'd')
		instruction->size +=
			(!g_op_tab[instruction->op_code].byte_dir) ? DIR_SIZE : IND_SIZE;
	else
		instruction->size += IND_SIZE;
}
