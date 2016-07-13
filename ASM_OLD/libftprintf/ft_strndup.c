/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 03:31:20 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/22 21:45:53 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strndup(const char *s, int n)
{
	char	*dest;
	int		i;

	i = -1;
	dest = (char*)malloc(sizeof(char) * n + 1);
	if (!dest)
		ft_malloc_error();
	while (s[++i] && n--)
		dest[i] = s[i];
	dest[i] = 0;
	return (dest);
}
