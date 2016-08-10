/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 20:24:27 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/10 20:52:17 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_file_content(t_data *data)
{
	t_file_line		*tmp;
	t_file_line		*actual_line;

	actual_line = data->file_content;
	while (actual_line)
	{
		tmp = actual_line;
		actual_line = actual_line->next;
		free(tmp->line);
		free(tmp);
	}
}
