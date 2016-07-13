/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 04:22:03 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/14 04:22:11 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!del || !alst)
		return ;
	del((**alst).content, (**alst).content_size);
	free(*alst);
	*alst = NULL;
}
