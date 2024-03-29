/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_comment_definition_error.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 15:35:54 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 17:18:09 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	display_comment_definition_error(char *file, t_data *data)
{
	t_file_line		*node;
	char			first_display;

	if (!data->has_comment)
		return ((void)display_error("No [.comment] declaration", file));
	first_display = 0;
	node = data->file_content;
	ft_printf("%[[FG_RED,SP_BOL,SP_RST]s ", "ERROR");
	ft_printf("%[[FG_YEL,SP_BOL,SP_RST]s ", "->");
	ft_printf("%[[FG_MAG,SP_RST]s : Multiple [.comment] declaration. ", file);
	while (node)
	{
		if (node->is_comment)
		{
			if (!first_display++)
				ft_printf("[%[[FG_GRE,SP_RST]d]", node->line_number);
			else
				ft_printf(" | [%[[FG_GRE,SP_RST]d]", node->line_number);
		}
		node = node->next;
	}
	ft_printf(".\n");
}
