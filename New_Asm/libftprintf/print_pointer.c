/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:36 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:36 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	get_info(t_flags *flag, t_info *list)
{
	if (flag->nb_max_char > (int)ft_strlen(list->tmp_third))
	{
		flag->nb_min_char -= (2 + flag->nb_max_char);
		flag->nb_max_char -= ft_strlen(list->tmp_third);
		if (list->tmp_third[0] == 48)
			++flag->nb_max_char;
	}
	else
	{
		flag->nb_max_char = 0;
		flag->nb_min_char -= (2 + ft_strlen(list->tmp_third));
	}
}

void			print_pointer(t_flags *flag, va_list *va, t_info *list)
{
	void	*x;

	x = va_arg(*va, void*);
	list->tmp_third = itoa_base(x, 16, flag);
	flag->i = -1;
	get_info(flag, list);
	if (flag->zero)
		bufferjoin(list, "0x", 2);
	while (!flag->minus &&
			flag->is_min_area_size_here && ++flag->i < flag->nb_min_char)
		flag->zero ? bufferujoin(list, 48) : bufferujoin(list, 32);
	if (!flag->zero)
		bufferjoin(list, "0x", 2);
	flag->i = -1;
	while (flag->is_precision_here && ++flag->i < flag->nb_max_char)
		bufferujoin(list, 48);
	if (!flag->is_precision_here || (flag->is_precision_here &&
				list->tmp_third[0] != 48))
		bufferjoin(list, list->tmp_third, ft_strlen(list->tmp_third));
	flag->i = -1;
	while (flag->minus &&
			flag->is_min_area_size_here && ++flag->i < flag->nb_min_char)
		bufferujoin(list, 32);
	free(list->tmp_third);
}
