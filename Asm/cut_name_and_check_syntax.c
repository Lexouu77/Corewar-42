/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_name_and_check_syntax.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 18:00:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 19:07:22 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		cut_name_and_check_syntax(char *file, t_data *data)
{
	t_file_line	*node;

	node = data->file_content;
	while (node && !node->is_name)
		node = node->next;
	if (get_nb_c(node->line, '"') < 2)
		return (display_error_line("Missing dquotes during [.name] declaration",
					file, node->line_number));
	return (0);
}
