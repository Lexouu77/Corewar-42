/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:32:25 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/13 17:48:14 by adjivas          ###   ########.fr       */
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

	arena->number_of_process = 0;
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
	int		i;
	t_proc	*process;

	i = -1;
	while (++i < arena->mem_size)
		arena->fresh_field[i] =
			arena->fresh_field[i] == 0 ? 0 : arena->fresh_field[i] - 1;
	arena->cycles++;
	process = arena->last_process;
	if ((arena->verbosity & 2) == 2)
		ft_printf_fd(arena->fd, "We're now in the cycle number : %d\n",
				arena->cycles);
	while (process)
	{
		increment_waiting_time(arena, process);
		check_instruction_from_proc(arena, process);
		arena->format = arena->field[((process->pc + 1) % arena->mem_size)];
		execute_instruction(arena, process);
		process = process->prev;
	}
}

void			play(t_vm_data *arena)
{
	set_players_in_game(arena);
	init_list(arena);
	if (arena->loop_dump)
		dump_and_wait(arena);
	if (arena->graph == 1 && !core_start(arena->players->number_of_player))
		core_display_info_player(arena);
	while (1)
	{
		loop_process(arena);
		refresh_field(arena);
		if (arena->graph == 1)
		{
			core_idle(arena->field, arena->color_field, arena->process_field);
			core_display_info(arena);
		}
		if (arena->dump && arena->cycles % arena->cycles_to_dump == 0)
			dump(arena);
		if (arena->loop_dump && arena->cycles % arena->cycles_to_loop_dump == 0)
			dump_and_wait(arena);
		if (arena->cycles == arena->next_cycle_check)
			if (!is_someone_in_game(arena))
				break ;
	}
}
