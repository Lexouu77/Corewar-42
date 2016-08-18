/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:39 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:39 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			stock_n(va_list *va, t_flags *flag, t_info *list)
{
	void	*n;

	n = va_arg(*va, void*);
	if (flag->sub_specifier[0] == 'h')
	{
		if (flag->sub_specifier[1] == 'h')
			*(char*)n = list->nb_c_written;
		*(short int*)n = list->nb_c_written;
	}
	if (flag->sub_specifier[0] == 'l')
	{
		if (flag->sub_specifier[1] == 'l')
			*(long long*)n = list->nb_c_written;
		*(long*)n = list->nb_c_written;
	}
	if (flag->sub_specifier[0] == 'j')
		*(long long*)n = list->nb_c_written;
	if (flag->sub_specifier[0] == 'z')
		*(size_t*)n = list->nb_c_written;
	*(long long*)n = list->nb_c_written;
}
