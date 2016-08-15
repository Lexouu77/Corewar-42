/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 04:43:32 by ahamouda          #+#    #+#             */
/*   Updated: 2016/07/05 04:43:32 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_to_zero(t_flags *current_flag)
{
	current_flag->i = -1;
	while (++current_flag->i < 10)
	{
		current_flag->precision[current_flag->i] = 0;
		current_flag->min_area_size[current_flag->i] = 0;
	}
	current_flag->is_min_area_size_here = 0;
	current_flag->is_precision_here = 0;
	current_flag->sub_specifier[0] = 0;
	current_flag->sub_specifier[1] = 0;
	current_flag->fg_color = FG_NO;
	current_flag->bg_color = BG_NO;
	current_flag->special = SPE_NO;
	current_flag->reset_fg = 0;
	current_flag->reset_bg = 0;
	current_flag->reset_ansi = 0;
}

t_flags		*init_flags(void)
{
	t_flags		*current_flag;

	if (!(current_flag = (t_flags*)malloc(sizeof(t_flags))))
		ft_malloc_error();
	current_flag->type = 0;
	current_flag->nb_max_char = 0;
	current_flag->nb_c_written = 0;
	current_flag->nb_min_char = 0;
	current_flag->plus = 0;
	current_flag->minus = 0;
	current_flag->space = 0;
	current_flag->zero = 0;
	set_to_zero(current_flag);
	current_flag->star = 0;
	current_flag->hash = 0;
	current_flag->dot_star = 0;
	return (current_flag);
}
