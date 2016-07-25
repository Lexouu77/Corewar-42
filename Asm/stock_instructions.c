/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 13:57:23 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/25 21:33:33 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
			add_new_instruction(label, node->line + goto_end_label(node->line));
		if (node->is_instruction && !node->is_label)
			add_new_instruction(label, node->line);
		node = node->next;
	}
}
