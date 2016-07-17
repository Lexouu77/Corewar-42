/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_name_from_file_content.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 17:44:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 22:05:12 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	remove_name_from_file_content(t_data *data)
{
	t_file_line	*node;
	t_file_line	*to_delete;

	node = data->file_content;
	if (node->is_name)
	{
		data->file_content = data->file_content->next;
		return (free(node));
	}
	while (node && node->next)
	{
		if (node->next->is_name)
		{
			to_delete = node->next;
			node->next = node->next->next;
			return (free(to_delete));
		}
		to_delete = node;
		node = node->next;
	}
	to_delete->next = NULL;
	free(node);
}
