/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_someone_in_game.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 23:12:38 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/16 19:09:38 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_kill_player(t_player *player, t_vm_data *arena)
{
	player->to_kill = 0;
	player->still_in_game = 0;
	if ((arena->verbosity & 4) == 4)
		ft_printf_fd(arena->fd, "Player number : %d just died !\n",
				player->number_of_player);
}
static void	soft_kill_player(t_vm_data *arena)
{
	t_player	*player;

	player = arena->players;
	while (player)
	{
		if (!player->alive && player->still_in_game)
			display_kill_player(player, arena);
		player = player->next;
	}
}

int			is_someone_in_game(t_vm_data *arena)
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
	soft_kill_player(arena);
	check_period(arena);
	return (1);
}
