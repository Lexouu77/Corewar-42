/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:42 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:42:42 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*byte_swap(void *toswap, size_t size)
{
	unsigned char	tmp;
	unsigned char	*swap;
	size_t			i;

	i = size / 2;
	swap = (unsigned char *)toswap;
	while (i > 0)
	{
		tmp = *(swap + i - 1);
		*(swap + i - 1) = *(swap + size - i);
		*(swap + size - i) = tmp;
		i--;
	}
	return ((void *)swap);
}
