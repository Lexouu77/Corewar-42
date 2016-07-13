/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 03:17:10 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/11 03:17:39 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrepl(char *src, char to_find, char c)
{
	int i;

	i = -1;
	while (src[++i])
		if (src[i] == to_find)
			src[i] = c;
	return (src);
}
