/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 17:04:21 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/06 13:39:52 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		create_cor_file(char *file, t_data *data)
{
	int			fd;
	const int	len = ft_strlen(file);
	char		*new_file;
	char		*tmp;

	tmp = ft_strndup(file, len - 2);
	new_file = ft_strjoin(tmp, ".cor");
	free(tmp);
	if ((fd = open(new_file, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
	{
		free(new_file);
		return ((void)display_error("Couldn't create the file", file));
	}
	if (data->display_instruction_info)
		display_instruction_info(data);
	write_cor_header(fd, data);
	write_cor_body(fd, data);
	display_success(new_file);
	free(new_file);
}
