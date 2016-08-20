/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicode_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:37 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:37 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_unicode_char(va_list *va, t_flags *flag, t_info *list)
{
	void	*x;
	int		len;

	flag->i = -1;
	x = va_arg(*va, void*);
	len = get_unicode_len((int)x);
	if (!flag->is_min_area_size_here)
		return (bufferujoin(list, (int)x));
	else
	{
		while (!flag->minus && ++flag->i < flag->nb_min_char - len)
			flag->zero ? bufferujoin(list, 48) : bufferujoin(list, 32);
		bufferujoin(list, (int)x);
		while (flag->minus && ++flag->i < flag->nb_min_char - len)
			flag->zero ? bufferujoin(list, 48) : bufferujoin(list, 32);
	}
}
