/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:00 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:00 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *p_s = s;

	++n;
	--p_s;
	while (--n)
		if (*++p_s == (unsigned char)c)
			return ((void*)p_s);
	return (NULL);
}
