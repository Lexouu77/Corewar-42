/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:45 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/11 18:53:25 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	const char	*nptr = str;
	int			sign;
	int			result;

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
	while (*nptr && ft_isdigit(*nptr))
		result = result * 10 + (*(nptr++) - 48);
	return (sign ? -result : result);
}
