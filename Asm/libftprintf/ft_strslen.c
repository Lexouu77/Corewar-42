/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 00:22:11 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/17 22:09:04 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_strslen(const char *s, char *to_find)
{
	size_t	i;

	i = 0;
	if (s && to_find)
		while (s[i] && ft_strncmp(s + i, to_find, ft_strlen(to_find)))
			++i;
	return (i);
}
