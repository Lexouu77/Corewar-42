/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 15:01:57 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 16:12:44 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_name(t_data *data)
{
	t_file_line		*node;

	node = data->file_content;
	while (node)
	{
		if (!ft_strncmp(node->line, ".name", 5))
		{
			node->is_name = 1;
			data->has_name++;
		}
		node = node->next;
	}
}
