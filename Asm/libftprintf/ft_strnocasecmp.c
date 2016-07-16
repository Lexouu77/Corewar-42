/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnocasecmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 02:48:35 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/16 20:00:21 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_case(char a, char b)
{
	if (ft_isalpha(b) && ft_isalpha(a))
	{
		if ((a < 97 && (a + 32) == b) || (a > 90 && (a - 32) == b))
			return (1);
	}
	return (0);
}

int			ft_strnocasecmp(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	while (*s1)
	{
		if (*s1 != *s2 && !check_case(*s1, *s2))
			return (((unsigned char)*s1 - (unsigned char)*s2));
		++s1;
		++s2;
	}
	return ((*s1 - *s2));
}
