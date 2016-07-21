/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_label_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 16:19:49 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/20 16:28:57 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		delete_label_list(t_label_list *list)
{
	t_label_list	*p_lst;
	t_label_list	*tmp;

	if (!list)
		return ;
	p_lst = list;
	while (p_lst)
	{
		tmp = p_lst;
		p_lst = p_lst->next;
		free(tmp->label_name);
		free(tmp);
	}
}
