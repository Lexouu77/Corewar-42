/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_size_to_label.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:36:30 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/04 22:23:03 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		is_before(t_asm_data *data, char *label_to_find, char *name)
{
	t_label			*label;

	label = data->labels;
	if (name && label_to_find && !ft_strcmp(label_to_find, name))
		return (1);
	while (label && label->name != name)
	{
		if (label->name && !ft_strcmp(label_to_find, label->name))
			return (1);
		label = label->next;
	}
	return (0);
}

static void	get_negative_size(t_instruction *instr, t_asm_data *data,
		char *to_find)
{
	t_label			*label;
	t_instruction	*instruc;
	int				size;
	int				i;

	size = 0;
	label = data->labels;
	while (label)
	{
		if (label->name && !ft_strcmp(to_find, label->name))
			break ;
		label = label->next;
	}
	while (label)
	{
		instruc = label->instructions;
		while (instruc)
		{
			if (instruc == instr)
				break ;
			i = -1;
			size += instruc->bytes_size;
			instruc = instruc->next;
		}
		label = label->next;
	}
	i = -1;
	while (++i < instruc->number_of_args)
		if (!instruc->args_value[i])
			break ;
	instruc->args_value[i] = -size;
}

static void	get_positive_size(t_instruction *instr, t_label *label,
		char *to_find)
{
	t_label			*lab;
	t_instruction	*instruc;
	int				size;
	int				i;

	instruc = instr;
	size = 0;
	if (!label->next)
		return ;
	lab = label->next;
	while (instruc)
	{
		size += instruc->bytes_size;
		instruc = instruc->next;
	}
	while (lab)
	{
		if (lab->name && !ft_strcmp(lab->name, to_find))
			break ;
		instruc = lab->instructions;
		while (instruc)
		{
			size += instruc->bytes_size;
			instruc = instruc->next;
		}
		lab = lab->next;
	}
	i = -1;
	while (++i < instr->number_of_args)
		if (!instr->args_value[i])
			break ;
	instr->args_value[i] = size;
}

static void	loop_label(t_instruction *instr, t_asm_data *data, t_label *label)
{
	int	i;

	i = -1;
	while (++i < instr->number_of_label_called)
	{
		if (is_before(data, instr->label_called[i], label->name))
			get_negative_size(instr, data, instr->label_called[i]);
		else
			get_positive_size(instr, label, instr->label_called[i]);
	}
}

void	get_distance_to_label(t_asm_data *data)
{
	t_label			*label;
	t_instruction	*instr;

	label = data->labels;
	while (label)
	{
		instr = label->instructions;
		while (instr)
		{
			loop_label(instr, data, label);
			instr = instr->next;
		}
		label = label->next;
	}
}
