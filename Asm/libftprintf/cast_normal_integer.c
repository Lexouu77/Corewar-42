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
			return (x);
		return (x);
	}
	if (flag->sub_specifier[0] == 'l')
	{
		if (flag->sub_specifier[1] == 'l')
			return (x);
		return (x);
	}
	if (flag->sub_specifier[0] == 'j')
		return (x);
	if (flag->sub_specifier[0] == 'z')
		return (x);
	return (x);
}

void			*cast_normal_integer(t_flags *flag, void *x)
{
	if (flag->type == 'U' || flag->type == 'O')
		return (x);
	if (flag->type == 'D')
		return (x);
	if (flag->type == 'u' || flag->type == 'o' || flag->type == 'x' ||
			flag->type == 'X')
		return (cast_unsigned_int(flag, x));
	if (flag->sub_specifier[0] == 'h')
	{
		if (flag->sub_specifier[1] == 'h')
			return (x);
		return (x);
	}
	if (flag->sub_specifier[0] == 'l')
	{
		if (flag->sub_specifier[1] == 'l')
			return (x);
		return (x);
	}
	if (flag->sub_specifier[0] == 'j')
		return (x);
	if (flag->sub_specifier[0] == 'z')
		return (x);
	return (x);
}
