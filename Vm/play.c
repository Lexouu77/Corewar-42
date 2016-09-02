/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:32:25 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/02 03:55:10 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


static void		refresh_field(t_vm_data *arena)
{
	t_player	*player;
	t_proc		*process;
	int			i;

//	ft_bzero(arena->process_field, arena->mem_size);
	i = -1;
	while (++i < arena->mem_size)
		arena->process_field[i] = 0;
	player = arena->players;
	while (player)
	{
		process = player->process;
		while (process)
		{
			arena->process_field[process->pc % arena->mem_size] = process->father->number_of_player;
			process = process->next;
		}
		player = player->next;
	}
}

void			play(t_vm_data *arena)
{
	int		i;
	set_players_in_game(arena);
	//display_field(arena);
	while (1) //set un moment ou stop ? if cycle_delta == 1 ?
	{
//		if (arena->graph)
//			termion_display(arena);
		i = -1;
		while (++i < arena->mem_size)
			arena->fresh_field[i] = 0;
		//ft_bzero(arena->fresh_field, arena->mem_size);
		arena->cycles++;
		increment_waiting_time(arena);
		check_instruction_from_proc(arena);
		execute_instruction(arena);
		refresh_field(arena); // refresh process_field 
//		display_field(arena);
//		sleep(1);
		if (arena->dump && arena->cycles % arena->cycles_to_dump == 0)
			dump(arena);
		if (arena->loop_dump && arena->cycles % arena->cycles_to_loop_dump == 0)
				dump_and_wait(arena);
		if (arena->cycles == arena->next_cycle_check)
			if (!is_someone_in_game(arena))
				break ;
	}
}
