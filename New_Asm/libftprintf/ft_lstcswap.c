/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:55 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:42:55 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstcswap(t_list *lst1, t_list *lst2)
{
	void	*tmpcontent;
	size_t	tmpsize;

	tmpcontent = lst1->content;
	tmpsize = lst1->content_size;
	lst1->content = lst2->content;
	lst1->content_size = lst2->content_size;
	lst2->content = tmpcontent;
	lst2->content_size = tmpsize;
}
