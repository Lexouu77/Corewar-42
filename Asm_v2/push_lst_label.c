/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lst_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 00:13:51 by ahamouda          #+#    #+#             */
/*   Updated: 2016/04/30 00:15:46 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		push_lst_label(t_label **begin, t_label *to_add)
{
	t_label	*tmp;

	if (!to_add || !begin || !*begin)
		return ;
	tmp = *begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = to_add;
}
