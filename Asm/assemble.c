/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 07:50:46 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 00:29:31 by ahamouda         ###   ########.fr       */
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
	check_name(data); // cherche les .name "x" et les stock.
	if (data->has_name != 1)
		;// error too many/no name declaration present in the file
	remove_name_from_file_content(data);
	check_comment(data);
	if (data->has_comment != 1)
		;// error too many/no comment declaration present in the file
	remove_comment_from_file_content(data);

}
