/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 21:42:08 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/02 08:10:34 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_live(t_proc *process, int number, t_vm_data *arena)
{
	if ((arena->verbosity & 8) == 8)
	{
		ft_printf_fd(arena->fd, "Process number : %d",
				process->number);
		ft_printf_fd(arena->fd, " owned by player number : %d",
				process->father->number_of_player);
		ft_printf_fd(arena->fd, " says that the player number : %d", number);
		ft_printf_fd(arena->fd, " is alive!\n");
	}
}

static void	display_live_instruction(t_proc *process, t_vm_data *arena)
{
	if ((arena->verbosity & 1) == 1)
	{
		ft_printf_fd(arena->fd, "Process number : %d",
				process->number);
		ft_printf_fd(arena->fd, " owned by player number : %d",
				process->father->number_of_player);
		ft_printf_fd(arena->fd, " is doing a live!\n");
	}
}

void		live(t_vm_data *arena, t_proc *process)
{
	int			tmp;
	t_player	*player;

	display_live_instruction(process, arena);
	tmp = get_param_value(arena, process->pc + 1, get_n_param_size(arena, 1));
	tmp = -tmp;
	move_pc_without_format(arena, process);
	display_live(process, tmp, arena);
	process->lives++;
	if (tmp > MAX_PLAYERS || tmp < 1)
		return ;
	player = arena->players;
	while (player)
	{
		if (player->number_of_player == tmp)
		{
			player->alive++; // if alive == 1 make sound
			player->period_live_number++;
			player->cycle_of_last_live = arena->cycles;
		}
		player = player->next;
	}
}
