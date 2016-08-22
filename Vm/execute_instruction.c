/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 05:37:05 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/22 19:51:34 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		execute_instruction(t_vm_data *arena)
{
	t_player	*player;
	t_proc		*process;
	static void		(*f[16])(t_vm_data *, t_proc *) = {live, load, store,
		add, sub, do_and, do_or, do_xor, zjump, load_index, store_index,
		do_fork, long_load, long_load_index, long_fork, aff};

	player = arena->last_player;
	while (player)
	{
		process = player->last_process;
		while (process)
		{
			if (process->is_waiting &&
					process->cycles_waiting == process->cycles_to_wait)
			{
				arena->format =
					arena->field[(process->pc + 1) % arena->mem_size];
				f[arena->field[process->pc] - 1](arena, process);
				process->is_waiting = 0;
				process->cycles_waiting = 0;
				process->cycles_to_wait = 0;
			}
			process = process->prev;
		}
		player = player->prev;
	}
}
