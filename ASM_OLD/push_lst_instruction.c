/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lst_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 00:16:03 by ahamouda          #+#    #+#             */
/*   Updated: 2016/05/17 12:51:09 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		push_lst_instruction(t_instruction **begin, t_instruction *to_add)
{
	t_instruction	*tmp;

	if (!to_add || !begin)
		return ;
	if (!*begin)
	{
		*begin = to_add;
		return ;
	}
	tmp = *begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = to_add;
}
