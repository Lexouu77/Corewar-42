/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 21:51:29 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/10 20:47:06 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Setting line to NULL on purpose since gnl free line if line != NULL
*/

static void	check_read_return(int read_return)
{
	if (read_return == -1)
		ft_error("Gnl returned -1.");
}

void		stock_file_content(t_data *data, int fd)
{
	char	*line;
	char	*tmp;
	int		read_return;

	while ((read_return = get_next_line(fd, &line)) > 0)
	{
		if (ft_is_str_space(line) || line_starts_with_comment(line))
		{
			free(line);
			line = NULL;
			continue ;
		}
		if (ft_isspace(line[0]) || ft_isspace(line[ft_strlen(line)]))
		{
			tmp = ft_strtrim(line);
			free(line);
			line = tmp;
		}
		if (line_has_comment(line))
			line = remove_comment_from_line(line);
		add_file_content_line(data, line);
		line = NULL;
	}
	check_read_return(read_return);
	free(line);
}
