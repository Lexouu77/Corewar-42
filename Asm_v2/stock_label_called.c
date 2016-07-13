/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_label_called.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:23:44 by ahamouda          #+#    #+#             */
/*   Updated: 2016/05/24 09:51:53 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*get_label_name(char *line)
{
	char		*label;

	if (ft_strxlen(line + 2, ',') < ft_strxlen(line + 2, 32))
		label = ft_strndup(line + 2, ft_strxlen(line + 2, ','));
	else
		label = ft_strndup(line + 2, ft_strxlen(line + 2, 32));
	return (label);
}

void			stock_label_called_name(t_instruction *instr, char *line)
{
	char			**cpy;
	int				i;
	char			*label;

	label = get_label_name(line);
	if (instr->number_of_label_called == 1)
	{
		if (!(instr->label_called = (char **)malloc(sizeof(char *) * 1)))
			ft_malloc_error();
		instr->label_called[0] = label;
		return ;
	}
	else
	{
		i = -1;
		cpy = instr->label_called;
		free(instr->label_called);
		if (!(instr->label_called = (char **)malloc(sizeof(char *) *
						instr->number_of_label_called)))
			ft_malloc_error();
		while (++i < instr->number_of_label_called)
			instr->label_called[i] = cpy[i];
		instr->label_called[i] = label;
	}
}
