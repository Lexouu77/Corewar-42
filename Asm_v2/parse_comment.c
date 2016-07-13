/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:19:19 by sjulliot          #+#    #+#             */
/*   Updated: 2016/05/17 13:02:36 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define EMPTY_COMMENT_STRING	".comment \"\""
#define EMPTY_COMMENT_LEN		ft_strlen(EMPTY_COMMENT_STRING)

int					line_is_comment(char *line)
{
	const size_t	len = ft_strlen(line);

	if (len <= EMPTY_COMMENT_LEN
		|| ft_strncmp(line, EMPTY_COMMENT_STRING, EMPTY_COMMENT_LEN - 1)
		|| line[len - 1] != '"')
		return (0);
	return (1);
}

void				extract_comment_from_line(char *line, t_asm_data *data)
{
	const int		len = ft_strlen(line) - EMPTY_COMMENT_LEN;

	if (data->comment)
		data->error = MULTIPLE_COMMENT_DEFINITIONS;
	else
		data->comment = ft_strndup(line + EMPTY_COMMENT_LEN - 1, len);
}

int					has_comment(t_asm_data *data)
{
	if (!data->comment)
	{
		data->error = MISSING_COMMENT;
		return (0);
	}
	return (1);
}
