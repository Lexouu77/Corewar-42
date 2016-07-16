/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file_content_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 22:11:48 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 00:34:34 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_file_content_line(t_data *data, char *line)
{
	t_file_line		*new_node;
	t_file_line		*tmp;
	int				line_number;

	new_node = ft_memalloc(sizeof(t_file_line));
	if (!data->file_content)
	{
		new_node->line = line;
		new_node->line_number = 1;
		data->file_content = new_node;
		return ;
	}
	tmp = data->file_content;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		line_number = tmp->line_number;
	}
	tmp->next = new_node;
	new_node->line_number = tmp->line_number + 1;
}
