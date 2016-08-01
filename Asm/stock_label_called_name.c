/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_label_called_name.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 10:28:48 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 13:07:12 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	stock_label_called_name(t_instruction *instruction, char *s)
{
	char	**cpy;
	int		i;
	char	*label;

	label = (get_shorten_len(s) < (int)ft_strxlen(s, LABEL_CHAR))?
		ft_strndup(s, get_shorten_len(s)) : ft_strndup(s,
				ft_strxlen(s, LABEL_CHAR));
	if (instruction->number_of_label_called == 1)
	{
		instruction->label_called = ft_memalloc(sizeof(char *) * 1);
		instruction->label_called[0] = label;
		return ;
	}
	else
	{
		i = -1;
		cpy = instruction->label_called;
		free(instruction->label_called);
		instruction->label_called = ft_memalloc(sizeof(char *) *
				instruction->number_of_label_called);
		while (++i < instruction->number_of_label_called)
			instruction->label_called[i] = cpy[i];
		instruction->label_called[i] = label;
	}
	free(cpy);
}
