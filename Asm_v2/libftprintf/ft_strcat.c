/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 09:14:02 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/27 09:18:33 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int len;

	len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[len + i] = src[i];
		++i;
	}
	dest[len + i] = '\0';
	return (dest);
}
