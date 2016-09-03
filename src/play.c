/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:32:25 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/03 17:25:16 by adjivas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


extern int32_t core_start();
extern int32_t core_end();

extern int32_t core_idle (
		int32_t *fields,
		int32_t *colors,
		int32_t *procs
		);

static void		refresh_field(t_vm_data *arena)
{
	t_player	*player;
	t_proc		*process;
	int			i;

	i = -1;
	while (++i < arena->mem_size)
		arena->process_field[i] = 0;
	player = arena->players;
	while (player)
	{
		process = player->process;
		while (process)
		{
			arena->process_field[process->pc % arena->mem_size] =
				process->owner;
			process = process->next;
		}
		player = player->next;
	}
}

void			play(t_vm_data *arena)
{
	int		i;
	set_players_in_game(arena);
	core_start();
	while (1)
	{
		core_idle(arena->field, arena->color_field, arena->process_field);
		i = -1;
		while (++i < arena->mem_size)
		arena->fresh_field[i] = 0;
		arena->cycles++;
		increment_waiting_time(arena);
		check_instruction_from_proc(arena);
		execute_instruction(arena);
		refresh_field(arena);
		//		if (arena->graph)
		//			termion_display(arena);
		if (arena->dump && arena->cycles % arena->cycles_to_dump == 0)
			dump(arena);
		if (arena->loop_dump && arena->cycles % arena->cycles_to_loop_dump == 0)
			dump_and_wait(arena);
		if (arena->cycles == arena->next_cycle_check)
			if (!is_someone_in_game(arena))
				break ;
	}
}
