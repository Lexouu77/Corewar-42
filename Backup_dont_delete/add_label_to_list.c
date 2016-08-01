/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_label_to_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 16:19:37 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/20 16:48:58 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		add_label_to_list(char *name, t_data *data, int line_number)
{
	t_label_list	*node;
	t_label_list	*new_node;

	new_node = ft_memalloc(sizeof(t_label_list));
	new_node->label_name = name;
	new_node->line_number = line_number;
	if (!data->label_list)
	{
		data->label_list = new_node;
		return ;
	}
	node = data->label_list;
	while (node && node->next)
		node = node->next;
	node->next = new_node;
}
