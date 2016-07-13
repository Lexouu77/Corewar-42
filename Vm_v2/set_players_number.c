/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_players_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 09:26:39 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/13 10:16:24 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	is_number_available(int n, t_vm_data *arena)
{
	int			i;
	t_player	*players;

	players = arena->players;
	i = -1;
	while (++i < 4 && players)
	{
		if (players->number_of_player == n)
			return (0);
		players = players->next;
	}
	return (1);
}

void		set_players_number(t_vm_data *arena)
{
	t_player	*players;
	int			i;
	int			j;

	j = 0;
	while (++j < 5)
	{
		players = arena->players;
		i = 0;
		while (++i < 5 && players)
		{
			if (players->number_of_player > 4 || players->number_of_player < 1)
				players->number_of_player = -1;
			if (players->number_of_player == -1 &&
					is_number_available(j, arena))
				players->number_of_player = j;
			players = players->next;
		}
	}
}
