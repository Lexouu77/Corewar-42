/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmxlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:16 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:44:50 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_not(char c, char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (0);
	return (1);
}

size_t		ft_stmrxlen(const char *s, char *c)
{
	size_t	i;

	i = 0;
	while (s[i] && is_not(s[i], c))
		++i;
	return (i);
}
