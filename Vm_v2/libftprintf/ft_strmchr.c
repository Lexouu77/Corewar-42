/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 07:42:00 by ahamouda          #+#    #+#             */
/*   Updated: 2016/04/20 08:04:18 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strmchr(char *s, char *to_find)
{
	int		i;
	int		j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (to_find[++j])
			if (s[i] != to_find[j])
				return (1);
	}
	return (0);
}
