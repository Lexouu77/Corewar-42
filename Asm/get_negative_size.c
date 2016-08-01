/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_negative_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 11:40:35 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 12:01:38 by ahamouda         ###   ########.fr       */
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
	while (tmp_label && ft_strcmp(tmp_label->name, label_name))
	{
		while (tmp_instruction)
		{
			size += tmp_instruction->size;
			tmp_instruction = tmp_instruction->prev;
		}
		tmp_label = tmp_label->prev;
		tmp_instruction = get_last_instruction_node(tmp_label);
	}
	i = -1;
	while (++i < instruction->number_of_args)
		if (!instruction->parameter_value[i])
			break ;
	instruction->parameter_value[i] = -size;
}
