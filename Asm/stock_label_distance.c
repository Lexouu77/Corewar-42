/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_label_distance.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 11:02:26 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 11:55:03 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define ARGS label, instruction->label_called[i], instruction

void	stock_label_distance(t_data *data)
{
	t_label			*label;
	t_instruction	*instruction;
	int				i;

	label = data->label;
	while (label)
	{
		instruction = label->instruction;
		while (instruction)
		{
			i = -1;
			while (++i < instruction->number_of_label_called)
			{
				if (is_label_called_before(label, instruction->label_called[i]))
					get_negative_size(ARGS);
				else
					get_positive_size(ARGS);
			}
			instruction = instruction->next;
		}
		label = label->next;
	}
}
