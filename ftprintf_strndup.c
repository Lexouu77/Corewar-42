/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_strndup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:27:18 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/06 15:40:01 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ftprintf_strndup(const char *s, int n)
{
	char	*dest;
	int		i;

	i = -1;
	dest = ft_strnew(n);
	while (++i < n)
		dest[i] = s[i];
	dest[i] = 0;
	return (dest);
}
