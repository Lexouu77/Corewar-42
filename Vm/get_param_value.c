/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 22:42:53 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/30 23:08:02 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static long	get_shift_value(long shift)
{
	if (shift == 24)
		return (0xFF000000);
	if (shift == 16)
		return (0x00FF0000);
	if (shift == 8)
		return (0x0000FF00);
	return (0x000000FF);
}

long			get_param_value(t_vm_data *arena, int pc, int size)
{
	long	value;
	long	shift;
	long	i;

//	pc = (pc + 1) % IDX_MOD;
	i = 0;
	value = 0;
	shift = 8 * (size - 1);
	while (shift >= 0)
	{
		value |= ((arena->field[(pc + i++) % arena->mem_size] << shift) &
							get_shift_value(shift));
		shift -= 8;
	}
	return (value);
}
