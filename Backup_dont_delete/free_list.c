/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 08:50:13 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/15 08:58:25 by ahamouda         ###   ########.fr       */
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
		free(tmp->args_type);
		free(tmp->args_value);
		free(tmp->args_byte_size);
		free(tmp);
	}
}
