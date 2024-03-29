/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_players_in_game.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 21:47:03 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/02 01:41:05 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		set_players_in_game(t_vm_data *arena)
{
	t_player	*player;

	set_last_player(arena);
	player = arena->players;
	while (player && player->next)
	{
		player->last_process = player->process;
		player->still_in_game = 1;
		player->number_of_process++;
		player = player->next;
	}
	player->last_process = player->process;
	player->still_in_game = 1;
	player->number_of_process++;
	arena->last_player = player;
	arena->winner = arena->last_player->number_of_player;
	if ((arena->verbosity & 2) == 2)
		ft_printf_fd(arena->fd, "First check at cycle : %d\n",
				arena->next_cycle_check);
}
