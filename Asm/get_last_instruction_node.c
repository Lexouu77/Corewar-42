/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_instruction_node.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 11:48:14 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/27 11:54:57 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_instruction	*get_last_instruction_node(t_label	*label)
{
	t_instruction	*tmp;

	tmp = label->instruction;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}
