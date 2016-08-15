/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:23 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:23 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strstr(const char *s, const char *s_to_find)
{
	int len;

	len = ft_strlen(s_to_find);
	if (!len)
		return ((char *)s);
	while (*s)
		if (!ft_memcmp(s++, s_to_find, len))
			return ((char *)s - 1);
	return (NULL);
}
