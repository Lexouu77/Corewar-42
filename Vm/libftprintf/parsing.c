/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:33 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:33 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_printf_check_flags(t_flags *flag, char *str, va_list *va,
		t_info *list)
{
	while (is_a_good_flag_or_type(str) && !flag->type)
	{
		if (is_a_valid_type(*str))
			str = get_type(flag, str);
		else if (is_a_sub_specifier(*str))
			str = get_sub_specifier(flag, str);
		else if (*str == 48 || *str == 32 || *str == 35)
			str = get_zero_or_space_or_hash(flag, str);
		else if (*str == 45 || *str == 43)
			str = get_operator(flag, str);
		else if (*str == 46 && *(str + 1) == 42)
			str = get_dot_star(flag, str, va);
		else if (*str == 42)
			str = get_star(flag, str, va);
		else if (*str == 46)
			str = get_precision(flag, ++str);
		else if (ft_isdigit(*str))
			str = get_min_area_size(flag, str);
		else if (*str == 91 && str[1] == 91)
			str = get_ansi_code(flag, ++str, list);
	}
	if (*str)
		flag->type = (flag->type) ? flag->type : *str++;
	return (str);
}
