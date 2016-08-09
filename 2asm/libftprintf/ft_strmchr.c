/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:15 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:15 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strmchr(char *s, char *to_find)
{
	int		i;
	int		j;
	int		ret;

	i = -1;
	while (s[++i])
	{
		ret = 0;
		j = -1;
		while (to_find[++j])
			if (s[i] == to_find[j])
				ret = 1;
		if (!ret)
			return (0);
	}
	return (1);
}
