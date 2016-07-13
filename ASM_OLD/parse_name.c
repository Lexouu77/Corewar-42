/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 12:51:18 by ahamouda          #+#    #+#             */
/*   Updated: 2016/05/17 12:51:33 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define EMPTY_NAME_STRING	".name \"\""
#define EMPTY_NAME_LEN		ft_strlen(EMPTY_NAME_STRING)

int					line_is_name(char *line)
{
	const size_t	len = ft_strlen(line);

	if (len <= EMPTY_NAME_LEN
		|| ft_strncmp(line, EMPTY_NAME_STRING, EMPTY_NAME_LEN - 1)
		|| line[len - 1] != '"')
		return (0);
	return (1);
}

void				extract_name_from_line(char *line, t_asm_data *data)
{
	const int		len = ft_strlen(line) - EMPTY_NAME_LEN;

	if (data->name)
		data->error = MULTIPLE_NAME_DEFINITIONS;
	else
		data->name = ft_strndup(line + EMPTY_NAME_LEN - 1, len);
}

int					has_name(t_asm_data *data)
{
	if (!data->name)
	{
		data->error = MISSING_NAME;
		return (0);
	}
	return (1);
}
