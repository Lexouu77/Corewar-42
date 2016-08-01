/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_already_exist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 16:10:00 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/20 16:37:21 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			label_already_exist(t_data *data, char *label_name_to_test)
{
	t_label_list	*node;

	node = data->label_list;
	while (node)
	{
		if (!ft_strcmp(label_name_to_test, node->label_name))
			return (node->line_number);
		node = node->next;
	}
	return (0);
}
