/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_comment_from_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 23:56:12 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/24 16:29:53 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*remove_comment_from_line(char *line)
{
	char	*tmp;
	char	*dest;
	size_t	len;

	len = ft_strslen(line, "//");
	if (len > ft_strslen(line, "#"))
		len = ft_strslen(line, "#");
	if (len > ft_strslen(line, ";"))
		len = ft_strslen(line, ";");
	tmp = ft_strndup(line, len);
	free(line);
	if (ft_isspace(tmp[0]) || ft_isspace(tmp[ft_strlen(tmp)]))
	{
		dest = ft_strtrim(tmp);
		free(tmp);
		return (dest);
	}
	return (tmp);
}
