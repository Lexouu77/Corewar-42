/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_data_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 20:13:34 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/11 17:47:33 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	delete_data_label(t_data *data)
{
	t_label			*tmp;
	t_label			*to_del;
	t_instruction	*tmp_instr;
	t_instruction	*to_del_instr;

	tmp = data->label;
	while (tmp)
	{
		tmp_instr = tmp->instruction;
		while (tmp_instr)
		{
			to_del_instr = tmp_instr;
			tmp_instr = tmp_instr->next;
			free(to_del_instr->parameter_type);
			free(to_del_instr->parameter_value);
			free(to_del_instr->parameter_size);
			free(to_del_instr);
		}
		to_del = tmp;
		tmp = tmp->next;
		free(to_del);
	}
}

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
	if (data->label)
		delete_data_label(data);
	ft_bzero(data, sizeof(t_data));
}
