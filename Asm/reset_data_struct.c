/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_data_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 20:13:34 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/18 21:41:16 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		reset_data_struct(t_data *data)
{
	if (!data)
		return ;
	if (data->name)
		free(data->name);
	if (data->comment)
		free(data->comment);
	if (data->file_content)
		free_file_content(data);
	data->file_content = NULL;
	data->error_line = 0;
	data->name = NULL;
	data->comment = NULL;
	data->has_name = 0;
	data->has_comment = 0;
	data->has_instructions = 0;
	data->display_byte_info = 0;
}

// bzero ?
