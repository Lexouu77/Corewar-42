/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:44 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:42:44 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		display_alpha_var(t_flags *flag, va_list *va, t_info *list)
{
	if (flag->type == 'c')
		print_normal_char(va, flag, list);
	if (flag->type == '%')
		print_char(flag, list);
	if (flag->type == 's')
		print_normal_string(va, flag, list);
	if (flag->type == 'C')
		print_unicode_char(va, flag, list);
	if (flag->type == 'S')
		print_unicode_string(va, flag, list);
}

void		display_spe_var(t_flags *flag, va_list *va, t_info *list)
{
	if (flag->type == 'n')
		stock_n(va, flag, list);
	else if (flag->type == 'p')
		print_pointer(flag, va, list);
	else if (flag->type == 'B' || flag->type == 'b')
		print_binary(flag, va, list);
	else if (flag->type == 'v')
		print_str_tab(va, list);
	else if (flag->type == 'V')
		print_int_tab(va, list);
}

void		display_numeric_var(t_flags *flag, va_list *va, t_info *list)
{
	if (flag->type == 'd' || flag->type == 'i' || flag->type == 'D' ||
			flag->type == 'u' || flag->type == 'U' || flag->type == 'x' ||
			flag->type == 'X' || flag->type == 'o' || flag->type == 'O')
		print_normal_integer(va, flag, list);
}
