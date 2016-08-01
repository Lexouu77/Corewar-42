/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction_label.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 21:58:48 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 13:30:46 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define NL node->line_number
#define NS node->line

int		check_instruction_label(char *file, t_data *data, t_file_line *node)
{
	const int	len = ft_strxlen(node->line, LABEL_CHAR);
	const char	*tmp = ft_strndup(node->line, len);
	const int	line = label_already_exist(data, (char*)tmp);
	int			i;

	if (!len)
		return (display_error_line("No label name", file, NL, -1));
	node->is_label = 1;
	if (data->label_list && line)
		return (display_label_error(node->line_number, (char*)tmp, file, line));
	add_label_to_list((char*)tmp, data, NL);
	if (ft_strlen(NS + len + 1) < 1 || ft_is_str_space(NS + len + 1))
		return (1);
	else
	{
		i = 0;
	//	while (node->line[len + 1 + i] && ft_isspace(node->line[len + 1 +i]))
	//		i++;
		return (check_instruction_line(file, data, node, len + i + 1));
	}
	return (1);
}
