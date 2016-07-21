/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 09:15:54 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/27 10:14:23 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		ft_malloc_error();
	ft_memset(mem, 0, size);
	return (mem);
}
