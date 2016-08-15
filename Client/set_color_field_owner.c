/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_field_owner.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 22:42:31 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 19:32:51 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	set_color_field_owner(t_vm_data *arena, int size, t_proc *process,
		int index)
{
	if (size == 2)
	{
		arena->color_field[process->pc + index] = process->owner;
		arena->color_field[process->pc + index + 1] = process->owner;
	}
	if (size == 4)
	{
		arena->color_field[process->pc + index] = process->owner;
		arena->color_field[process->pc + index + 1] = process->owner;
		arena->color_field[process->pc + index + 2] = process->owner;
		arena->color_field[process->pc + index + 3] = process->owner;
	}
	else
		arena->color_field[process->pc + index] = process->owner;
}
