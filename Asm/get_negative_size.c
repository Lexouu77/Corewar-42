/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_negative_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 11:40:35 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/06 17:35:38 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_negative_size(t_label *label, char *label_name,
		t_instruction *instruction)
{
	int				size;
	t_label			*tmp_label;
	t_instruction	*tmp_instruction;
	int				i;

	size = 0;
	tmp_label = label;
	tmp_instruction = instruction->prev;
	if (!instruction)
	{
		tmp_label = tmp_label->prev;
		if (tmp_label)
			tmp_instruction = get_last_instruction_node(tmp_label);
	}
	while (tmp_label)
	{
		while (tmp_instruction)
		{
			size += tmp_instruction->size;
			tmp_instruction = tmp_instruction->prev;
		}
		if (!ft_strcmp(label_name, tmp_label->name) && !tmp_instruction)
			break ;
		tmp_label = tmp_label->prev;
		if (tmp_label)
			tmp_instruction = get_last_instruction_node(tmp_label);
	}
	i = -1;
	while (++i < instruction->number_of_args)
		if (instruction->parameter_type[i] == 'l' &&
				!instruction->parameter_value[i])
			break ;
	instruction->parameter_value[i] = -size;
}
