/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_normal_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:35 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:35 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_normal_char(va_list *va, t_flags *flag, t_info *list)
{
	void	*x;
	char	transformed_x;

	if (flag->sub_specifier[0] == 'l' && !flag->sub_specifier[1])
		return (print_unicode_char(va, flag, list));
	flag->i = -1;
	x = va_arg(*va, void*);
	transformed_x = (int)x;
	if (!flag->is_min_area_size_here)
		return (bufferjoin(list, &transformed_x, 1));
	else
	{
		while (!flag->minus && ++flag->i < flag->nb_min_char - 1)
			flag->zero ? bufferujoin(list, 48) : bufferujoin(list, 32);
		bufferjoin(list, &transformed_x, 1);
		while (flag->minus && ++flag->i < flag->nb_min_char - 1)
			flag->zero ? bufferujoin(list, 48) : bufferujoin(list, 32);
	}
}
