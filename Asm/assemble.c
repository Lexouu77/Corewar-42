/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 07:50:46 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/25 20:38:45 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		assemble(char *file, t_data *data)
{
	if (!is_file_valid(file))
		return ;
	if ((data->fd = open(file, O_RDONLY)) == -1)
		return ((void)display_error("Couldn't open the file", file));
	stock_file_content(data, data->fd);
	close(data->fd);
	check_name(data);
	if (data->has_name != 1)
		return (display_name_definition_error(file, data));
	if (!cut_name_and_check_syntax(file, data))
		return ;
	remove_name_from_file_content(data);
	check_comment(data);
	if (data->has_comment != 1)
		return (display_comment_definition_error(file, data));
	if (!cut_comment_and_check_syntax(file, data))
		return ;
	remove_comment_from_file_content(data);
	if (!check_instructions(file, data))
		return ;
	if (!check_label_called(file, data) || !check_empty_label(file, data))
		return ;
	stock_instructions(data); // free les instructions TODO : ADD UN PREV/NEXT dans label et instr pour plus tard.
	create_cor_file(file, data);
}
