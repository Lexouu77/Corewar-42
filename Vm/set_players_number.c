/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_players_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 09:26:39 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/13 18:33:48 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	is_number_available(int n, t_vm_data *arena)
{
	t_player	*players;

	players = arena->players;
	while (players)
	{
		if (players->number_of_player == n)
			return (0);
		players = players->next;
	}
	return (1);
}

static int	get_first_available_number(t_vm_data *arena)
{
	int	i;

	i = 0;
	while (++i < MAX_PLAYERS + 1)
		if (is_number_available(i, arena))
			break ;
	return (i);
}

void		set_players_number(t_vm_data *arena)
{
	t_player	*players;

	players = arena->players;
	while (players)
	{
		if (players->desired_number != -1 &&
				is_number_available(players->desired_number, arena))
			players->number_of_player = players->desired_number;
		else
			players->desired_number = -1;
		players = players->next;
	}
	while (players)
	{
		if (players->desired_number == -1 && players->number_of_player == 0)
			players->number_of_player = get_first_available_number(arena);
		players = players->next;
	}
}
