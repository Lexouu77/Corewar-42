/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_normal_integer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:36 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:36 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_without_minus(t_info *list, t_flags *flag)
{
	if (flag->zero && (flag->type == 'x' || flag->type == 'X') &&
			flag->hash && list->tmp_third[0] != 48)
		bufferjoin(list, (flag->type == 'x') ? "0x" : "0X", 2);
	if (flag->zero && flag->plus && flag->type != 'u' && flag->type != 'U')
		bufferujoin(list, flag->sign);
	if (flag->space && flag->type != 'u' && flag->type != 'U')
		bufferujoin(list, 32);
	while (flag->is_min_area_size_here && ++flag->i < flag->nb_min_char)
		flag->zero ? bufferujoin(list, 48) : bufferujoin(list, 32);
	flag->i = -1;
	if (!flag->zero && flag->plus && flag->type != 'u' && flag->type != 'U')
		bufferujoin(list, flag->sign);
	if (!flag->zero && (flag->type == 'x' || flag->type == 'X') &&
			flag->hash && list->tmp_third[0] != 48)
		bufferjoin(list, (flag->type == 'x') ? "0x" : "0X", 2);
	while (flag->is_precision_here && ++flag->i < flag->nb_max_char)
		bufferujoin(list, 48);
	if ((flag->type == 'o' || flag->type == 'O') && flag->hash)
		bufferujoin(list, 48);
	if (!flag->is_precision_here || (flag->is_precision_here &&
				list->tmp_third[0] != 48))
		bufferjoin(list, list->tmp_third, ft_strlen(list->tmp_third));
}

static	void	print_with_minus(t_info *list, t_flags *flag)
{
	if ((flag->type == 'o' || flag->type == 'O') && flag->hash)
		bufferujoin(list, 48);
	if ((flag->type == 'x' || flag->type == 'X') && flag->hash &&
			list->tmp_third[0] != 48)
		bufferjoin(list, (flag->type == 'x') ? "0x" : "0X", 2);
	if (flag->plus && flag->type != 'u' && flag->type != 'U')
		bufferujoin(list, flag->sign);
	if (flag->space && flag->type != 'u' && flag->type != 'U')
		bufferujoin(list, 32);
	while (flag->is_precision_here && ++flag->i < flag->nb_max_char)
		bufferujoin(list, 48);
	if (!flag->is_precision_here || (flag->is_precision_here &&
				list->tmp_third[0] != 48))
		bufferjoin(list, list->tmp_third, ft_strlen(list->tmp_third));
	flag->i = -1;
	while (flag->is_min_area_size_here && ++flag->i < flag->nb_min_char)
		bufferujoin(list, 32);
}

void			print_normal_integer(va_list *va, t_flags *flag, t_info *list)
{
	void				*x;
	unsigned long long	c_x;

	x = va_arg(*va, void*);
	x = cast_normal_integer(flag, x);
	c_x = (unsigned long long)get_sign(x, flag);
	if (flag->type == 'd' || flag->type == 'i' || flag->type == 'u' ||
			flag->type == 'U' || flag->type == 'D')
		list->tmp_third = itoa_base((void*)c_x, 10, flag);
	if (flag->type == 'x' || flag->type == 'X')
		list->tmp_third = itoa_base((void*)c_x, 16, flag);
	if (flag->type == 'o' || flag->type == 'O')
		list->tmp_third = itoa_base((void*)c_x, 8, flag);
	get_nb_min_char(flag, list->tmp_third);
	flag->i = -1;
	if (flag->minus)
		print_with_minus(list, flag);
	if (!flag->minus)
		print_without_minus(list, flag);
	free(list->tmp_third);
}
