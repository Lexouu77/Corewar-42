/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_param_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 23:23:36 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/05 22:43:58 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_param_value(t_vm_data *arena, int pc, int value, t_proc *process)
{
	int	shift;
	int	i;

	i = 0;
	shift = 24;
	while (shift >= 0)
	{
		arena->fresh_field[(pc + i) % arena->mem_size] = 50;
		arena->color_field[(pc + i) % arena->mem_size] = process->owner;
		arena->field[(pc + i++) % arena->mem_size] = ((value >> shift) & 0xFF);
		shift -= 8;
	}
}
