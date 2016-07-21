/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 03:34:14 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/11 03:35:34 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strxdup(const char *s, char c)
{
	char	*dest;
	int		i;
	int		len;

	len = 0;
	i = -1;
	while (s[len] != c || s[len])
		++len;
	dest = (char*)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (++i < len)
		dest[i] = s[i];
	dest[len] = 0;
	return (dest);
}
