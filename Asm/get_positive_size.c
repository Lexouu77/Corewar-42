/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positive_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 11:40:29 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 11:56:33 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_positive_size(t_label *label, char *label_name,
		t_instruction *instruction)
{
	int				size;
	t_label			*tmp_label;
	t_instruction	*tmp_instruction;
	int				i;

	size = 0;
	tmp_label = label;
	tmp_instruction = instruction;
	while (tmp_label && ft_strcmp(tmp_label->name, label_name))
	{
		while (tmp_instruction)
		{
			size += tmp_instruction->size;
			tmp_instruction = tmp_instruction->next;
		}
		tmp_label = tmp_label->next;
		tmp_instruction = tmp_label->instruction;
	}
	i = -1;
	while (++i < instruction->number_of_args)
		if (!instruction->parameter_value[i])
			break ;
	instruction->parameter_value[i] = -size;
}
