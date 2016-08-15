/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_someone_in_game.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 23:12:38 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 23:21:30 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		is_someone_in_game(t_vm_data *arena)
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
	return (1);
}
