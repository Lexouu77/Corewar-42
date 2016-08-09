/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_data_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 20:13:34 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/21 16:26:40 by ahamouda         ###   ########.fr       */
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
	if (data->label_list)
		delete_label_list(data->label_list);
	ft_bzero(data, sizeof(t_data));
}
