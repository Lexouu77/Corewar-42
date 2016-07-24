/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:30 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:30 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			*get_sign(void *x, t_flags *flag)
{
	const long long		c = (long long)x;
	unsigned long long	i_c;

	i_c = -c;
	if (c < 0)
		flag->sign = '-';
	else
		flag->sign = '+';
	if (flag->sign == '-')
		flag->plus = 1;
	if (flag->plus)
		flag->space = 0;
	if (flag->sign == '-' && (flag->type == 'd' || flag->type == 'i' ||
				flag->type == 'D'))
		return ((void*)i_c);
	if (flag->type == 'o' || flag->type == 'O' ||
			flag->type == 'x' || flag->type == 'X')
	{
		flag->plus = 0;
		flag->space = 0;
	}
	return (x);
}
