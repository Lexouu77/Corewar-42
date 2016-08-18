/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 21:42:08 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/18 22:38:49 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	is_player_in_game(int number, t_vm_data *arena)
{
	t_player	*player;

	player = arena->players;
	while (player)
	{
		if (player->number_of_player == number && player->still_in_game)
			return (1);
		player = player->next;
	}
	return (0);
}

static void	display_live(t_proc *process, int number, t_vm_data *arena)
{
	ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
	ft_printf_fd(arena->fd, " owned by player number : %d",
			process->father->number_of_player);
	ft_printf_fd(arena->fd, " says that the player number : %d", number);
	ft_printf_fd(arena->fd, " is alive!\n");
}

static void	display_live_instruction(t_proc *process, t_vm_data *arena)
{
	ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
	ft_printf_fd(arena->fd, " owned by player number : %d",
			process->father->number_of_player);
	ft_printf_fd(arena->fd, " is doing a live!\n");
}

void		live(t_vm_data *arena, t_proc *process)
{
	int			tmp;
	t_player	*player;
	int			size;

	if ((arena->verbosity & 8) == 8)
		display_live_instruction(process, arena);
	tmp = get_direct_arg_value(arena, process, &size);
	process->pc = (process->pc + size + 1) % arena->mem_size;
	if ((arena->verbosity & 1) == 1)
		display_live(process, tmp, arena);
	arena->period_live_number++;
	if ((tmp > MAX_PLAYERS || tmp < 1) && !is_player_in_game(tmp, arena))
		return ;
	process->lives++;
	player = arena->players;
	while (player)
	{
		if (player->number_of_player == tmp)
		{
			player->alive = 1;
			player->period_live_number++;
			player->cycle_of_last_live = arena->cycles;
		}
		player = player->next;
	}
}
