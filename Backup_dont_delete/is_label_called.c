/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_label_called.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 00:29:30 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/22 13:49:32 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	is_label_called(char *s, t_data *data)
{
	char			*tmp;
	t_label_list	*list;

	tmp = ft_strndup(s, get_shorten_len(s));
	list = data->label_list;
	while (list)
	{
		if (!ft_strcmp(list->label_name, tmp))
		{
			free(tmp);
			return (1);
		}
		list = list->next;
	}
	free(tmp);
	return (0);
}
