/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 02:17:16 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/11 02:17:30 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
