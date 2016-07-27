/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 15:27:35 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 08:41:33 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_new_label(t_data *data, char *name)
{
	t_label		*tmp;
	t_label		*prev;
	t_label		*new_label;

	new_label = ft_memalloc(sizeof(t_label));
	new_label->name = name;
	if (!data->label)
	{
		data->label = new_label;
		return ;
	}
	tmp = data->label;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = new_label;
	new_label->prev = prev;
}
