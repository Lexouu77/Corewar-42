/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_normal_integer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:42:43 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	*cast_unsigned_int(t_flags *flag, void *x)
{
	if (flag->sub_specifier[0] == 'h')
	{
		if (flag->sub_specifier[1] == 'h')
			return ((void*)(unsigned long long)(unsigned char)x);
		return ((void*)(unsigned long long)(unsigned short)x);
	}
	if (flag->sub_specifier[0] == 'l')
	{
		if (flag->sub_specifier[1] == 'l')
			return ((void*)(unsigned long long)(unsigned long long)x);
		return ((void*)(unsigned long long)(unsigned long)x);
	}
	if (flag->sub_specifier[0] == 'j')
		return ((void*)(unsigned long long)x);
	if (flag->sub_specifier[0] == 'z')
		return ((void*)(unsigned long long)(size_t)x);
	return ((void*)(unsigned long long)(unsigned int)x);
}

void			*cast_normal_integer(t_flags *flag, void *x)
{
	if (flag->type == 'U' || flag->type == 'O')
		return ((void*)(unsigned long long)(unsigned long)x);
	if (flag->type == 'D')
		return ((void*)(long long)(long)x);
	if (flag->type == 'u' || flag->type == 'o' || flag->type == 'x' ||
			flag->type == 'X')
		return (cast_unsigned_int(flag, x));
	if (flag->sub_specifier[0] == 'h')
	{
		if (flag->sub_specifier[1] == 'h')
			return ((void*)(long long)(char)x);
		return ((void*)(long long)(short)x);
	}
	if (flag->sub_specifier[0] == 'l')
	{
		if (flag->sub_specifier[1] == 'l')
			return ((void*)(long long)x);
		return ((void*)(long long)(long)x);
	}
	if (flag->sub_specifier[0] == 'j')
		return ((void*)(long long)x);
	if (flag->sub_specifier[0] == 'z')
		return ((void*)(long long)(size_t)x);
	return ((void*)(long long)(int)x);
}
