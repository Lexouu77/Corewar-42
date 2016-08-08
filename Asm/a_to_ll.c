/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_ll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 13:51:14 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/08 08:20:10 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

long long	a_to_ll(char *nptr)
{
	long long	sign;
	long long	result;

	sign = 0;
	result = 0;
	while (ft_isspace(*nptr) && *nptr)
		++nptr;
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
			sign = 1;
		++nptr;
	}
	while (ft_isdigit(*nptr) && *nptr)
	{
		result *= 10;
		result += (*nptr - 48);
		++nptr;
	}
	if (sign)
		return (-result);
	return (result);
}
