/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_instruction_info.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 11:57:17 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 12:37:47 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	display_instruction_info(t_data *data)
{
	t_label				*label;
	t_instruction		*instruction;
	int					total_size;

	total_size = 0;
	label = data->label;
	while (label)
	{
		instruction = label->instruction;
		while (instruction)
		{
			display_line_info(instruction, &total_size);
			display_parameter_info(instruction);
			instruction = instruction->next;
		}
		label = label->next;
	}
}
