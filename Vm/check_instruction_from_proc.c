/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction_from_proc.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 03:19:28 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 22:27:47 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		check_instruction_from_proc(t_vm_data *arena)
{
	t_player	*player;
	t_proc		*process;

	player = arena->players;
	while (player)
	{
		process = player->process;
		while (process)
		{
			if (!process->is_waiting)
			{
				if (arena->field[process->pc] > 0 && 
						arena->field[process->pc] < 16)
				{
					process->is_waiting = 1;
					process->cycles_to_wait =
					g_op_tab[arena->field[process->pc] - 1].cycles_to_process;
				}
				else
					process->pc = (process->pc + 1) % arena->mem_size;
			}
			process = process->next;
		}
		player = player->next;
	}
}
