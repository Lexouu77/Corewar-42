/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:33 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:33 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	get_base_char(int c, t_flags *flag)
{
	if (c >= 10 && c <= 15)
		return (flag->type < 96) ? (65 + (c - 10)) : (97 + (c - 10));
	return (48 + c);
}

char		*itoa_base(void *x, int base, t_flags *flag)
{
	char					*str;
	int						size;
	unsigned long long		nb;

	nb = (unsigned long long)x;
	size = 1;
	while (nb /= base)
		++size;
	str = ft_strnew(size);
	nb = (unsigned long long)x;
	while (--size >= 0)
	{
		str[size] = get_base_char((nb % base), flag);
		nb /= base;
	}
	return (str);
}
