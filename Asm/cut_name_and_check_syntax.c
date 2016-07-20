/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_name_and_check_syntax.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 18:00:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/20 20:12:02 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define EM0 "Name too long during [.name] declaration"
#define EM1 "Missing dquotes during [.name] declaration"
#define EM2 "Missing name during [.name] declaration"
#define EM3 "Invalid character during [.name] declaration"
#define EM4 "Too many dquotes during [.name] declaration"
#define EM5 "Empty name during [.name] declaration"
#define EMI (i + ft_strxlen(node->line + i, '"') + 1)

int		cut_name_and_check_syntax(char *file, t_data *data)
{
	t_file_line	*node;
	int			i;

	i = ft_strlen(NAME_CMD_STRING);
	node = data->file_content;
	while (node && !node->is_name)
		node = node->next;
	if (get_nb_c(node->line, '"') < 2)
		return (display_error_line(EM1, file, node->line_number, -1));
	if (get_nb_c(node->line, '"') > 2)
		return (display_error_line(EM4, file, node->line_number, -1));
	while (node->line[i] && ft_isspace(node->line[i]))
		i++;
	if (!node->line[i])
		return (display_error_line(EM2, file, node->line_number, -1));
	if (node->line[i] != '"')
		return (display_error_line(EM3, file, node->line_number, i));
	i++;
	if (ft_strlen(node->line + i) - 1 != ft_strxlen(node->line + i, '"'))
		return (display_error_line(EM3, file, node->line_number, EMI));
	if (node->line[i] == '"')
		return (display_error_line(EM5, file, node->line_number, i));
	if (ft_strxlen(node->line + i, '"') > PROG_NAME_LENGTH)
		return (display_error_line(EM0, file, node->line_number, i));
	return (stock_name(node, data, i));
}
