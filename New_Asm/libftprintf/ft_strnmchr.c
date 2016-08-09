/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnmchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:20 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:20 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strnmchr(char *s, char *to_find, int l)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	while (s[i] && i < l)
	{
		x = 0;
		j = -1;
		while (to_find[++j])
			if (s[i] == to_find[j])
				x = 1;
		if (!x)
			return (1);
		++i;
	}
	return (0);
}
