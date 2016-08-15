/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_invalid_players.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 23:01:06 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 19:28:24 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int		is_full_of_valid_players(t_vm_data *arena)
{
	t_player	*players;

	players = arena->players;
	while (players)
	{
		if (!players->validity)
			return (0);
		players = players->next;
	}
	return (1);
}

void			delete_invalid_players(t_vm_data *arena)
{
	t_player	*players;
	t_player	*tmp;

	if (is_full_of_valid_players(arena))
		return ;
	players = arena->players;
	arena->players = NULL;
	while (players)
	{
		if (players->validity)
		{
			if (!arena->players)
				arena->players = create_new_player(players->number_of_player,
						players->filename);
			else
				add_player(arena, players->number_of_player, players->filename);
		}
		tmp = players;
		players = players->next;
		free(tmp->filename);
		free(tmp);
	}
}
