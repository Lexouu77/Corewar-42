/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 09:14:10 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/27 09:24:44 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char		*p_dest;
	const char	*p_src = src;

	p_dest = dest;
	--p_dest;
	--p_src;
	while ((*++p_dest = *++p_src))
		;
	return (dest);
}
