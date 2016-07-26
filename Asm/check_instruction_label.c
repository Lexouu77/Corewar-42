/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction_label.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 21:58:48 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/26 07:16:35 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define NL node->line_number
#define NL_L node->line

int		check_instruction_label(char *file, t_data *data, t_file_line *node)
{
	const int	len = ft_strxlen(node->line, LABEL_CHAR);
	const char	*tmp = ft_strndup(node->line, len);
	const int	line = label_already_exist(data, (char*)tmp);

	if (!len)
		return (display_error_line("No label name", file, NL, -1));
	node->is_label = 1;
	if (data->label_list && line) // ??? check it
		return (display_label_error(node->line_number, (char*)tmp, file, line));
	add_label_to_list((char*)tmp, data, NL);
	if (ft_strlen(NL_L + len + 1) < 1 || ft_is_str_space(NL_L + len + 1))
		return (1);
	else
		return (check_instruction_line(file, data, node, len + 1));
	return (1);
}
