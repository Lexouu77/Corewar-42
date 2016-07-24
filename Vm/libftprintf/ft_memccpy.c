/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:59 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:42:59 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*p_dest;
	const char	*p_src = src;

	if (!dest || !src)
		return (NULL);
	p_dest = dest;
	while (n--)
	{
		*p_dest++ = *p_src;
		if (*p_src == c)
			return (p_dest);
		p_src++;
	}
	return (NULL);
}
