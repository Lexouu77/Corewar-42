/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:25 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:25 by ahamouda         ###   ########.fr       */
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
