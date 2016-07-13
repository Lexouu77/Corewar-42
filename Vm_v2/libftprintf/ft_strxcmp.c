/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 16:06:22 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/27 16:07:30 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strxcmp(const char *s1, const char *s2, int n)
{
	if (!s1 && !s2)
		return (0);
	while (*s1 && n)
	{
		if (*s1 != *s2)
			return (((unsigned char)*s1 - (unsigned char)*s2));
		++s1;
		++s2;
		--n;
	}
	return ((*s1 - *s2));
}
