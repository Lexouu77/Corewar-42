/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sub_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:31 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:31 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	fill_sub_spe(t_flags *flag, int len)
{
	if (len == 1)
	{
		flag->sub_specifier[0] = 104;
		flag->sub_specifier[1] = 104;
		return ;
	}
	if (len == 4)
	{
		flag->sub_specifier[0] = 108;
		flag->sub_specifier[1] = 108;
		return ;
	}
	if (len == 2)
		flag->sub_specifier[0] = 104;
	if (len == 3)
		flag->sub_specifier[0] = 108;
	if (len == 5)
		flag->sub_specifier[0] = 'j';
	if (len == 6)
		flag->sub_specifier[0] = 'z';
	flag->sub_specifier[1] = 0;
}

static	int		check_max(t_flags *flag, int len2)
{
	int	len;

	if (flag->sub_specifier[0] == 104 && flag->sub_specifier[1] == 104)
		len = 1;
	if (flag->sub_specifier[0] == 104)
		len = 2;
	if (flag->sub_specifier[0] == 108)
		len = 3;
	if (flag->sub_specifier[0] == 108 && flag->sub_specifier[1] == 108)
		len = 4;
	if (flag->sub_specifier[0] == 'j')
		len = 5;
	if (flag->sub_specifier[0] == 'z')
		len = 6;
	if (len2 > len)
		fill_sub_spe(flag, len2);
	return ((len2 == 1 || len2 == 4) ? (2) : (1));
}

static	int		get_max(t_flags *flag, char *str)
{
	int	len;

	if (*str == 104 && *(str + 1) == 104)
		len = 1;
	if (*str == 104)
		len = 2;
	if (*str == 108)
		len = 3;
	if (*str == 108 && *(str + 1) == 108)
		len = 4;
	if (*str == 'j')
		len = 5;
	if (*str == 'z')
		len = 6;
	return (check_max(flag, len));
}

char			*get_sub_specifier(t_flags *flag, char *str)
{
	int	len;

	if (flag->sub_specifier[0])
	{
		len = get_max(flag, str);
		return (str + len);
	}
	if (*str == 104 && *(str + 1) == 104)
	{
		flag->sub_specifier[0] = 104;
		flag->sub_specifier[1] = 104;
		str += 2;
	}
	else if (*str == 108 && *(str + 1) == 108)
	{
		flag->sub_specifier[0] = 108;
		flag->sub_specifier[1] = 108;
		str += 2;
	}
	else
	{
		flag->sub_specifier[0] = *str;
		++str;
	}
	return (str);
}
