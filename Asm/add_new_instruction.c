/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 15:27:46 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/10 15:58:02 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*get_line_without_label(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != LABEL_CHAR)
		i++;
	++i;
	while (s[i] && (ft_isspace(s[i]) || s[i] == SEPARATOR_CHAR))
		++i;
	return (ft_strdup(s + i));
}

void		add_new_instruction(t_data *data, t_label *label, char *line,
		t_file_line *node)
{
	t_instruction	*new_instruction;
	t_instruction	*tmp;

	new_instruction = ft_memalloc(sizeof(t_instruction));
	if (node->is_label)
		new_instruction->raw_string = get_line_without_label(node->line);
	else
		new_instruction->raw_string = node->line;
	new_instruction->line_number = node->line_number;
	fill_instruction(data, new_instruction, line);
	if (!label->instruction)
	{
		label->instruction = new_instruction;
		return ;
	}
	tmp = label->instruction;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new_instruction;
	new_instruction->prev = tmp;
}
