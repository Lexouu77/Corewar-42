/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 08:24:04 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/27 09:04:51 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

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
