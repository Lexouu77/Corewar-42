/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_someone_in_game.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 23:12:38 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/12 06:18:55 by adjivas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		stock_players_live(t_vm_data *arena)
{
	t_player	*player;

	player = arena->players;
	while (player)
	{
		if (player->process)
			return (1);
		player = player->next;
	}
	return (0);
}

static void		display_kill_process(t_proc *process, t_vm_data *arena,
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

static t_proc	*kill_process(t_proc *process, t_player *player,
		t_vm_data *arena)
{
	t_proc	*tmp;

	tmp = process;
	if (process->lives)
	{
		process->lives = 0;
		return (process->next);
	}
	display_kill_process(process, arena, player);
	if (!process->next && !process->prev)
	{
		free(process->reg);
		free(process);
		player->process = NULL;
		player->last_process = NULL;
		return (NULL);
	}
	free(process->reg);
	if (!process->next)
	{
		player->last_process = process->prev;
		player->last_process->next = NULL;
		free(process);
		return (NULL);
	}
	process = process->next;
	process->prev = tmp->prev;
	if (tmp->prev)
		tmp->prev->next = process;
	if (tmp == player->process)
		player->process = process;
	free(tmp);
	return (process);
}

int				is_someone_in_game(t_vm_data *arena)
{
	t_player	*player;
	t_proc		*process;

	player = arena->players;
	while (player)
	{
		process = player->process;
		while (process)
			process = kill_process(process, player, arena);
		player = player->next;
	}
	if (!stock_players_live(arena))
	{
		kill_player(arena);
		return (0);
	}
	check_period(arena);
	return (1);
}
