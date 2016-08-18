/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:08 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:08 by ahamouda         ###   ########.fr       */
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
