/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cor_body.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 12:52:45 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/06 18:52:13 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_cor_body(int fd, t_data *data)
{
	t_label				*label;
	t_instruction		*instruction;
	int					i;

	label = data->label;
	while (label)
	{
		instruction = label->instruction;
		while (instruction)
		{
			i = -1;
			instruction->op_code++;
			write(fd, &(instruction->op_code), 1);
			if (g_op_tab[instruction->op_code - 1].byte_param)
				write(fd, &(instruction->format), sizeof(instruction->format));
			while (++i < instruction->number_of_args)
			{
				byte_swap(&(instruction->parameter_value[i]), instruction->parameter_size[i]);
				write(fd, &(instruction->parameter_value[i]), instruction->parameter_size[i]);
			}
			instruction = instruction->next;
		}
	label = label->next;
	}
}
