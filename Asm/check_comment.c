/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 15:02:02 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 15:36:46 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_comment(t_data *data)
{
	t_file_line		*node;

	node = data->file_content;
	while (node)
	{
		if (!ft_strncmp(node->line, ".comment", 8))
		{
			node->is_comment = 1;
			data->has_comment++;
		}
		node = node->next;
	}
}
