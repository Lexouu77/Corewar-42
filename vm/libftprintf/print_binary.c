/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:34 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:34 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_binary(t_flags *flag, va_list *va, t_info *list)
{
	void				*x;

	x = va_arg(*va, void*);
	list->tmp_third = itoa_base(x, 2, flag);
	bufferjoin(list, (flag->type == 'b') ? "0b" : "0B", 2);
	bufferjoin(list, list->tmp_third, ft_strlen(list->tmp_third));
	free(list->tmp_third);
}
