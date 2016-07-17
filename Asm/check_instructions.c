/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 23:16:35 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 23:56:28 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define NL node->line_number

int	check_instructions(char *file, t_data *data)
{
	t_file_line	*node;
	int		i;

	if (!data->file_content)
		return (display_error("No instructions in the file", file));
	node = data->file_content;
	while (node)
	{
		if (!check_forbidden_characters(node->line, &i))
			return (display_error_line("Invalid character", file, NL, i));
		node = node->next;
	}
	return (1);
}
