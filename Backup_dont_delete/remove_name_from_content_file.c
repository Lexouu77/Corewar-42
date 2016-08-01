/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_name_from_content_file.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 17:23:19 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 19:07:25 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	remove_name_from_content_file(t_data *data)
{
	t_file_line	*node;
	t_file_line	*to_delete;

	node = data->file_content;
	if (node->is_name)
	{
		data->file_content = data->file_content->next;
		data->name = node->line;
		return (free(node));
	}
	while (node && node->next)
	{
		if (node->next->is_name)
		{
			to_delete = node->next;
			data->name = node->line;
			node->next = node->next->next;
			return (free(to_delete));
		}
		to_delete = node;
		node = node->next;
	}
	data->name = node->line;
	to_delete->next = NULL;
	free(node);
}
