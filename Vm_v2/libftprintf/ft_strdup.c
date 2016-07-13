/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 08:24:55 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/27 09:25:11 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		ft_malloc_error();
	while (s[i])
	{
		dest[i] = s[i];
		++i;
	}
	dest[i] = 0;
	return (dest);
}
