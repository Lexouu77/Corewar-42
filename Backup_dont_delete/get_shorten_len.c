/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shorten_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 00:47:41 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/22 01:22:34 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_shorten_len(char *s)
{
	int		i;
	int		len;
	int		tmp;

	i = 9;
	len = ft_strxlen(s, i);
	while (++i < 14)
	{
		tmp = ft_strxlen(s, i);
		if (tmp < len)
			len = tmp;
	}
	tmp = ft_strxlen(s, 32);
	if (tmp < len)
		len = tmp;
	return (len);
}
