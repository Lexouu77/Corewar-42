/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:32:25 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 22:32:40 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"




int		is_someone_alive(t_vm_data *arena)
{
	t_player	*player;
	int			alive;

	alive = 0;
	player = arena->players;
	while (player)
	{
		if (player->alive)
			alive = 1;
		player = player->next;
	}
	if (!alive)
	{
		player = arena->players;
		while (player)
		{
			player->to_kill = 1;
			player = player->next;
		}
		kill_player(arena);
		return (0);
	}
	check_period(arena);
	kill_player(arena);
	return (1);
} // ???? ^^^^^^^^^^^^^^^ TODO : Add le check period

void			play(t_vm_data *arena)
{
	set_players_in_game(arena);
	while (1) //set un moment ou stop ? if cycle_delta == 1 ?
	{
		//refresh_fresh_field(arena);
		arena->cycles++;
		increment_waiting_time(arena);
		check_instruction_from_proc(arena);
		execute_instruction(arena);
		if (arena->dump && arena->cycles % arena->cycles_to_dump == 0)
			dump(arena);
		if (arena->loop_dump && arena->cycles % arena->cycles_to_loop_dump == 0)
				dump_and_wait(arena);
		if (arena->cycles == arena->next_cycle_check)
			if (!is_someone_alive(arena)) // changer par if cycle_delta == 1 ?
				break ;
	}
	kill_player(arena);
}
