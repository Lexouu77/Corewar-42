/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_label_called_before.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 11:36:17 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/06 13:21:19 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_label_called_before(t_label *label, char *label_name)
{
	t_label	*tmp;

	tmp = label;
	while (tmp)
	{
		if (tmp->name && !ft_strcmp(tmp->name, label_name))
			return (1);
		tmp = tmp->prev;
	}
	return (0);
}
