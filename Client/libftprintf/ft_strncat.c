/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:16 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:16 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *dest_start;

	dest_start = dest;
	while (*dest)
		++dest;
	++n;
	while (--n && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_start);
}
