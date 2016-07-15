/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_label_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 03:00:23 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/15 07:30:27 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_comment(char *s)
{
	int		i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		++i;
	if ((s[i] && (s[i] == '#' || s[i] == ';')) || (s[i] && s[i + 1] &&
								s[i] == '/' && s[i + 1] == '/'))
		return (1);
	return (0);
}

int			is_a_label(char *line)
{
	int		i;

	if (!ft_strchr(line, ':'))
		return (0);
	if (!ft_strxlen(line, ':'))
		return (0);
	i = -1;
	while (line[++i])
		if (ft_strlen(line + i) > 1 && line[i] != '%' &&
				line[i + 1] && line[i + 1] == ':')
			return (1);
	return (0);
}

t_label		*add_label_and_switch(t_asm_data *data, char *line,
		t_label *current_label)
{
	char	*label_name;

	label_name = ft_strndup(line, ft_strxlen(line, ':'));
	data->just_switched_label = 1;
	current_label->next = create_lst_label(label_name);
	return (current_label->next);
}

int			lines_are_correct(t_asm_data *data)
{
	t_instruction	*current_line;
	t_label			*current_label;

	data->error = NO_ERROR;
	current_line = data->lines;
	data->labels = create_lst_label(NULL);
	current_label = data->labels;
	while (current_line)
	{
		data->just_switched_label = 0;
		if (check_line_error(current_line->raw_string)) // ???
			return (0); /// a placer ailleurs 
		if (is_a_label(current_line->raw_string))
			current_label = add_label_and_switch(data, current_line->raw_string,
					current_label);
		if (data->just_switched_label) // && label_has_instructions(current_line))
			stock_instructions(data, current_line->raw_string +
					ft_strlen(current_label->name) + 2, current_label,
					current_line->line_number);
		else if (!data->just_switched_label)
			stock_instructions(data, current_line->raw_string, current_label,
					current_line->line_number);
		current_line = current_line->next;
	}
	return (1);
}
