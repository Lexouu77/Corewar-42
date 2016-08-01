/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 13:57:23 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 08:49:36 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define NS node->line

void	stock_instructions(t_data *data)
{
	t_file_line	*node;
	t_label		*label;

	create_label_list(data);
	node = data->file_content;
	label = data->label;
	while (node)
	{
		if (node->is_label)
			label = label->next;
		if (node->is_instruction && node->is_label)
			add_new_instruction(data, label, NS + go_to_end_of_label(NS));
		if (node->is_instruction && !node->is_label)
			add_new_instruction(data, label, NS);
		node = node->next;
	}
}
