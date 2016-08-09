/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:13 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:13 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t len_dest;
	size_t len_src;
	size_t size_origin;

	size_origin = size;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	while (*dest && size)
	{
		++dest;
		--size;
	}
	if (!size)
		return (size_origin + len_src);
	while (*src && size-- > 1)
		*dest++ = *src++;
	*dest = '\0';
	return (len_dest + len_src);
}
