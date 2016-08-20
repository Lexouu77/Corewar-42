/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_period.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 03:38:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 23:20:34 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	is_decrementing_needed(t_vm_data *arena)
{
	t_player	*player;

	player = arena->players;
	while (player)
	{
		arena->period_live_number += player->period_live_number;
		player = player->next;
	}
	if ((arena->number_of_checks > MAX_CHECKS ||
			arena->period_live_number >= NBR_LIVE) &&
			!arena->decrementing)
	{
		if ((arena->verbosity & 2) == 2)
			ft_printf_fd(arena->fd,
				"Cycle to die is now decrementing each period !!\n");
		return (1);
	}
	return (0);
}

static void	reset_player(t_player *player)
{
	player->to_kill = 0;
	player->alive = 0;
	player->period_live_number = 0;
}

static void	display_verbosity_check_period(t_vm_data *arena)
{
	ft_printf_fd(arena->fd, "Period number : %d\n", arena->number_of_checks);
	ft_printf_fd(arena->fd, "Live in this period : %d\n",
			arena->period_live_number);
	ft_printf_fd(arena->fd, "Next check at cycle : %d\n",
			arena->next_cycle_check);
}

void		check_period(t_vm_data *arena)
{
	t_player	*player;

	arena->number_of_checks++;
	if (!arena->decrementing && is_decrementing_needed(arena))
		arena->decrementing = 1;
	if (arena->cycles_to_die - arena->cycle_delta <= 0)
		arena->cycle_delta = 1;
	if (arena->decrementing)
		arena->cycles_to_die -= arena->cycle_delta;
	player = arena->players;
	while (player)
	{
		reset_player(player);
		player = player->next;
	}
	arena->next_cycle_check += arena->cycles_to_die;
	if ((arena->verbosity & 2) == 2)
		display_verbosity_check_period(arena);
	arena->period_live_number = 0;
}
