/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:42:44 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:42:44 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		display_final(t_flags *flag, va_list *va, t_info *list)
{
	if (is_a_valid_type(flag->type))
	{
		if (is_special_type(flag->type))
			display_spe_var(flag, va, list);
		else if (is_alphabetic_type(flag->type))
			display_alpha_var(flag, va, list);
		else
			display_numeric_var(flag, va, list);
	}
	else
		print_char(flag, list);
	if (flag->reset_ansi || flag->reset_bg || flag->reset_fg)
		apply_spe_after(flag, list);
}

char		*display_var(char *str, va_list *va, t_info *list)
{
	t_flags		*flag;

	flag = init_flags();
	str = ft_printf_check_flags(flag, str, va, list);
	if (flag->type)
		display_final(flag, va, list);
	free(flag);
	return (str);
}

static void	buffernjoin(t_info *list, char *str)
{
	char	*s;

	s = ftprintf_strndup(str, list->nb_c_needed);
	bufferjoin(list, s, list->nb_c_needed);
	free(s);
}

int			display(char *str, va_list *va, t_info *list)
{
	while (*str != 0)
	{
		if (*str == '%')
			str = display_var(++str, va, list);
		else
		{
			list->nb_c_needed = ft_strxlen(str, '%');
			buffernjoin(list, str);
			str += list->nb_c_needed;
		}
	}
	return (list->nb_c_written);
}
