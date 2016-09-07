/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:32:25 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/07 17:53:42 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		refresh_field(t_vm_data *arena)
{
	t_proc		*process;
	int			i;

	i = -1;
	while (++i < arena->mem_size)
		arena->process_field[i] = 0;
	//	arena->number_of_process += player->number_of_process;
	process = arena->last_process;
	while (process)
	{
		arena->process_field[process->pc % arena->mem_size] =
			process->owner;
		process = process->prev;
	}
}

static void		add_process_to_list(t_vm_data *arena, t_proc *to_add)
{
	t_proc	*process;

	if (!arena->process)
	{
		arena->process = to_add;
		arena->process->prev = NULL;
		arena->process->next = NULL;
		arena->last_process = to_add;
		return ;
	}
	process = arena->process;
	while (process && process->next)
		process = process->next;
	process->next = to_add;
	to_add->prev = process;
	to_add->next = NULL;
	arena->last_process = to_add;
}

static void		init_list(t_vm_data *arena)
{
	t_player	*player;

	arena->number_of_process = 0 ;
	player = arena->players;
	while (player)
	{
		add_process_to_list(arena, player->process);
		arena->number_of_process++;
		player = player->next;
	}
}

static void		loop_process(t_vm_data *arena)
{
	t_proc *process;

	process = arena->last_process;
	while (process)
	{
		increment_waiting_time(arena, process);
		check_instruction_from_proc(arena, process);
		execute_instruction(arena, process);
		process = process->prev;
	}
}

// TODO : FREE LA PROCESS LIST

void			play(t_vm_data *arena)
{
	int		i;
	set_players_in_game(arena);
	init_list(arena);
	if (arena->loop_dump)
		dump_and_wait(arena);
	while (1)
	{
		i = -1;
		while (++i < arena->mem_size)
		{
			if (arena->fresh_field[i] == 0)
				arena->fresh_field[i] = 0;
			else
				arena->fresh_field[i]--;
		}
		arena->cycles++;
		loop_process(arena);
//		increment_waiting_time(arena);
//		check_instruction_from_proc(arena);
//		execute_instruction(arena);
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
