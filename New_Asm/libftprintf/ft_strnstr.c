/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:20 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:20 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnstr(const char *s, const char *s_to_find, size_t n)
{
	size_t len;

	len = ft_strlen(s_to_find);
	if (!len)
		return ((char *)s);
	while (*s && len <= n--)
		if (!ft_memcmp(s++, s_to_find, len))
			return ((char *)s - 1);
	return (NULL);
}
