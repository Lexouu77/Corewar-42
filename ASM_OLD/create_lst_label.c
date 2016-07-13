/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_label.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 23:59:03 by ahamouda          #+#    #+#             */
/*   Updated: 2016/05/11 19:30:42 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label		*create_lst_label(char *label_name)
{
	t_label	*list;

	if (!(list = (t_label *)ft_memalloc(sizeof(t_label))))
		ft_malloc_error();
	if (label_name)
		list->name = ft_strdup(label_name);
	return (list);
}
