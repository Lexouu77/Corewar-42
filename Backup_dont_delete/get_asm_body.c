/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_asm_body.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 01:04:07 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/16 23:54:44 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_asm_body(int fd, t_instruction **instruction, unsigned int size)
{
	int				i;
	t_instruction	*instr;
	t_instruction	*tmp;

	i = size;
	instr = create_lst_instruction(NULL, i);
	*instruction = instr;
	while (i > 0)
	{
		if (!read_op_code(fd, instr, &i))
			break ;
		if (!read_format(fd, instr, &i))
			break ;
		if (!read_fixed_param_types(fd, instr, &i))
			break ;
		if (!read_param_value(fd, instr))
			break ;
		instr->next = create_lst_instruction(NULL, i);
		tmp = instr;
		instr = instr->next;
	}
	if (instr->op_code < 1 || instr->op_code > 16 || instr->number_of_args)
		free(instr);
	if (instr->op_code < 1 || instr->op_code > 16 || instr->number_of_args)
		tmp->next = NULL;
}
