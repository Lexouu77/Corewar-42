/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_negative_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 11:40:35 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/10 23:00:00 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	while_module(t_label *tmp_label, t_instruction *tmp_ins, int *size,
char *label_name)
{
	while (tmp_label)
	{
		while (tmp_ins)
		{
			(*size) += tmp_ins->size;
			tmp_ins = tmp_ins->prev;
		}
		if (!ft_strcmp(label_name, tmp_label->name) && !tmp_ins)
			break ;
		tmp_label = tmp_label->prev;
		if (tmp_label)
			tmp_ins = get_last_instruction_node(tmp_label);
	}
}

void		get_negative_size(t_label *label, char *label_name,
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
	while_module(tmp_label, tmp_instruction, &size, label_name);
	i = -1;
	while (++i < instruction->number_of_args)
		if (instruction->parameter_type[i] == 'l' &&
				!instruction->parameter_value[i])
			break ;
	instruction->parameter_value[i] = -size;
}
