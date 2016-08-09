/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label_called.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 18:08:25 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 13:28:50 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define NS node->line
#define NL node->line_number
#define NXTL go_to_next_label_call(node->line + index + i)

int	check_label_called(char *file, t_data *data)
{
	t_file_line	*node;
	int			i;
	int			index;

	node = data->file_content;
	if (!data->has_instructions)
		return (display_error("No instructions in the file", file));
	while (node)
	{
		index = 0;
		i = 0;
		while (index != -1)
		{
			ft_printf("rgsfgsgf");
			if ((i = has_a_label_call(NS + index)) != -1)
				if (!is_label_called(NS + index + i, data))
					return (display_label_call_error(NL, NS + index + i, file));
			if (i == -1)
				index = -1;
			if (i == -1)
				continue ;
			index = (NXTL) == -1 ? -1 : index + NXTL;
		}
		node = node->next;
	}
	return (1);
}
