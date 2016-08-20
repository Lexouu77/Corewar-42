/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:34 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:34 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_char(t_flags *flag, t_info *list)
{
	flag->i = -1;
	if (!flag->is_min_area_size_here)
		return (bufferujoin(list, flag->type));
	else
	{
		while (!flag->minus && ++flag->i < flag->nb_min_char - 1)
			flag->zero ? bufferujoin(list, 48) : bufferujoin(list, 32);
		bufferujoin(list, flag->type);
		while (flag->minus && ++flag->i < flag->nb_min_char - 1)
			bufferujoin(list, 32);
	}
}
