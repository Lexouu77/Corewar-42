/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:03:30 by ahamouda          #+#    #+#             */
/*   Updated: 2016/05/25 18:54:55 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op g_op_tab[];

t_instruction	*get_instruction(t_label *label, char *line, int line_number)
{
	t_instruction	*tmp;

	if (!label->instructions)
	{
		label->instructions = create_lst_instruction(line, line_number);
		return (label->instructions);
	}
	tmp = label->instructions;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = create_lst_instruction(line, line_number);
	return (tmp->next);
}

void			init_instruction(t_instruction *instr, int i)
{
	int		x;

	x = -1;
	instr->op_code = i + 1;
	instr->number_of_args = g_op_tab[i].arg_number;
	if (!(instr->args_type = (char*)malloc(sizeof(char)
					* g_op_tab[i].arg_number)) || !(instr->args_value =
			(int*)malloc(sizeof(int) * g_op_tab[i].arg_number)) ||
				!(instr->args_byte_size =
			(int*)malloc(sizeof(int) * g_op_tab[i].arg_number)))
		ft_malloc_error();
	while (++x < instr->number_of_args)
		instr->args_value[x] = 0;
}
