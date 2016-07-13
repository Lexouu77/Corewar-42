/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_winner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 23:07:11 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/11 23:16:52 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_player	*get_winner(t_vm_data *arena)
{
	t_player	*player;
	int			last_cycle;

	last_cycle = 0;
	player = arena->players;
	while (player)
	{
		if (player->cycle_of_last_live >= last_cycle)
			last_cycle = player->cycle_of_last_live;
		player = player->next;
	}
	player = arena->last_player;
	while (player)
	{
		if (player->cycle_of_last_live == last_cycle)
			return (player);
		player = player->prev;
	}
	return (arena->last_player);
}
