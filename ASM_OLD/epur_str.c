/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 13:49:41 by sjulliot          #+#    #+#             */
/*   Updated: 2016/05/11 20:04:17 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf/ft_printf.h"
#include "asm.h"

static size_t	next_space(char *str, size_t index)
{
	while (str[index] != '\0' && str[index] != ' ' && str[index] != '\t')
		index++;
	return (index);
}

static size_t	next_non_space(char *str, size_t index)
{
	while (str[index] != '\0' && (str[index] == ' ' || str[index] == '\t'))
		index++;
	return (index);
}

void			epur_str(char **line)
{
	char		*trimmed;
	char		*next;
	size_t		tmp_index;
	size_t		limit;

	limit = -1;
	if ((next = ft_strchr(*line, COMMENT_CHAR)))
		limit = next - *line;
	trimmed = ft_strtrim(*line);
	free(*line);
	*line = ft_strdup("");
	tmp_index = 0;
	while (tmp_index < limit && trimmed[tmp_index] != '\0')
	{
		next = ft_strsub(trimmed, tmp_index, next_space(trimmed,
														tmp_index) - tmp_index);
		*line = ft_strjoinsep_and_free(*line, next, ' ');
		free(next);
		tmp_index = next_non_space(trimmed, next_space(trimmed, tmp_index));
	}
	free(trimmed);
}
