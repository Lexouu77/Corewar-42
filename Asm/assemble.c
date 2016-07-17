/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 07:50:46 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 17:48:06 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		assemble(char *file, t_data *data)
{
	int		fd;

	if (!is_file_valid(file))
		return ;
	if ((fd = open(file, O_RDONLY)) == -1)
		return ((void)display_error("Couldn't open the file", file));
	stock_file_content(data, fd);
	close(fd);
	check_name(data);
	if (data->has_name != 1)
		return (display_name_definition_error(file, data));
	check_name_syntax_and_cut_it(file, data); // check les syntax error  + strndup
	remove_name_from_file_content(data);
	check_comment(data);
	if (data->has_comment != 1)
		return (display_comment_definition_error(file, data));
	check_comment_syntax_and_cut_it(file, data);
	remove_comment_from_file_content(data);

}
