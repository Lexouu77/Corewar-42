/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 22:42:53 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/18 23:00:46 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	get_shift_value(int shift)
{
	if (shift == 24)
		return (0xFF000000);
	if (shift == 16)
		return (0x00FF0000);
	if (shift == 8)
		return (0x0000FF00);
	return (0x000000FF);
}

int			get_param_value(t_vm_data *arena, int pc, int size)
{
	int	value;
	int	shift;
	int	i;

	i = 0;
	value = 0;
	shift = 6 * size;
	while (shift)
	{
		value |= ((arena->field[(pc + i++) % arena->mem_size] << shift) &
							get_shift_value(shift));
		shift -= 6;
	}
	return (value);
}
