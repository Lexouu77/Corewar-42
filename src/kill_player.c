/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 05:26:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/16 19:09:39 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_kill_process(t_proc *process, t_vm_data *arena,
		t_player *player)
{
	if ((arena->verbosity & 4) == 4)
	{
		ft_printf_fd(arena->fd, "Process number : %d", process->number);
		ft_printf_fd(arena->fd, " owned by player number : %d",
				player->number_of_player);
		ft_printf_fd(arena->fd, " just died !\n");
	}
}

static void	reset_player(t_player *player)
{
	player->process = NULL;
	player->last_process = NULL;
	player->filename = NULL;
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
			reset_player(player);
		}
		player = player->next;
	}
}
