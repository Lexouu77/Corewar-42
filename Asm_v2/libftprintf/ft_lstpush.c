/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 04:24:40 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/14 04:26:14 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*tmp;
	t_list	*beg;

	if (!new)
		return (NULL);
	if (!alst || !*alst)
		return (new);
	beg = *alst;
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (beg);
}
