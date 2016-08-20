/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:07 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/08 02:49:58 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	while (*s1)
	{
		if (*s1 != *s2)
			return (((unsigned char)*s1 - (unsigned char)*s2));
		++s1;
		++s2;
	}
	return ((*s1 - *s2));
}
