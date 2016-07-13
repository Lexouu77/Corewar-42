/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 05:26:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/14 14:37:18 by ahamouda         ###   ########.fr       */
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

static void	display_kill_process(t_proc *process, t_vm_data *arena,
		t_player *player)
{
	if ((arena->verbosity & 4) == 4)
	{
		ft_printf_fd(arena->fd, "Process number : %d", process->number);
		ft_printf_fd(arena->fd, " owned by player number : %d", player->number_of_player);
		ft_printf_fd(arena->fd, " just died !\n");
	}
}

void		kill_player(t_vm_data *arena)
{
	t_player	*player;
	t_proc		*process;
	t_proc		*tmp;

	player = arena->players;
	while (player)
	{
		process = player->process;
		if (player->to_kill && player->still_in_game)
		{
			display_kill_player(player, arena);
			while (process)
			{
				display_kill_process(process, arena, player);
				tmp = process;
				process = process->next;
				free(tmp->reg);
				free(tmp);
			}
			if (player->filename)
				free(player->filename);
			player->process = NULL;
			player->last_process = NULL;
			player->filename = NULL;
		}
		player = player->next;
	}
}
