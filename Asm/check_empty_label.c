/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty_label.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 04:05:25 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/06 10:50:58 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define EM1 "No instructions in label"

int	check_empty_label(char *file, t_data *data)
{
	t_file_line	*node;

	node = data->file_content;
	while (node)
	{
		if (((node->next && node->next->is_label) || (!node->next)) &&
				node->is_label && !node->is_instruction)
			return (display_error_line(EM1, file, node->next->line_number, -1));
		node = node->next;
	}
	return (1);
}
