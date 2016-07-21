/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnocasencmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 02:59:03 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/16 20:00:30 by ahamouda         ###   ########.fr       */
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

int			ft_strnocasencmp(const char *s1, const char *s2, int n)
{
	if ((!s1 && !s2) || !n)
		return (0);
	while (*s1 && n)
	{
		if (*s1 != *s2 && !check_case(*s1, *s2))
			return (((unsigned char)*s1 - (unsigned char)*s2));
		++s1;
		++s2;
		--n;
	}
	return ((*s1 - *s2));
}
