/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_strndup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:28 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:28 by ahamouda         ###   ########.fr       */
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
