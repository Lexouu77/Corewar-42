/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_label_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 20:38:31 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/25 21:26:05 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	create_label_list(t_data *data)
{
	t_label_list	*tmp;

	add_new_label(data, NULL);
	while(tmp)
	{
		add_new_label(data, ft_strdup(tmp->label_name));
		tmp = tmp->next;
	}
}
