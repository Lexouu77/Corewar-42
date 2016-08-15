/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:57 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:42:57 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list*start;
	t_list*new;
	t_list*tmp;

	if (!lst)
		return (NULL);
	tmp = NULL;
	start = NULL;
	while (lst)
	{
		new = f(ft_lstnew(lst->content, lst->content_size));
		if (!start)
			start = new;
		tmp = ft_lstpush(&tmp, new);
		lst = lst->next;
	}
	return (start);
}
