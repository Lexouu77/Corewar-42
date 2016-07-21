/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 15:01:57 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 23:38:39 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_name(t_data *data)
{
	t_file_line		*node;

	node = data->file_content;
	while (node)
	{
		if (!ft_strncmp(node->line, NAME_CMD_STRING,
					ft_strlen(NAME_CMD_STRING)))
		{
			node->is_name = 1;
			data->has_name++;
		}
		node = node->next;
	}
}
