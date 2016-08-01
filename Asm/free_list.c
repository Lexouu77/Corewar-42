/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 08:50:13 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 11:02:56 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_list(t_instruction *list)
{
	t_instruction	*p_lst;
	t_instruction	*tmp;

	if (!list)
		return ;
	p_lst = list;
	while (p_lst)
	{
		tmp = p_lst;
		p_lst = p_lst->next;
		free(tmp->parameter_type);
		free(tmp->parameter_value);
		free(tmp->parameter_size);
		free(tmp);
	}
}
