/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spe_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:30 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:30 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_dot_star(t_flags *flag, char *str, va_list *va)
{
	int		t;

	str += 2;
	flag->is_precision_here = 1;
	t = va_arg(*va, int);
	flag->nb_max_char = (t > 0) ? t : flag->nb_max_char;
	if (t < 0)
		flag->is_precision_here = 0;
	return (str);
}

char		*get_star(t_flags *flag, char *str, va_list *va)
{
	int		t;

	str++;
	flag->is_min_area_size_here = 1;
	t = va_arg(*va, int);
	flag->nb_min_char = (t >= 0) ? t : -t;
	if (t < 0)
		flag->minus = 1;
	return (str);
}
