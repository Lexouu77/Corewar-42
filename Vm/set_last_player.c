/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_last_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 16:44:07 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 22:18:48 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	set_last_player(t_vm_data *arena)
{
	t_player	*player;

	player = arena->players;
	if (arena->number_of_valid_player == 1)
	{
		 arena->last_player = arena->players;
		 return ;
	}
	while (player && player->next)
	{
		player->next->prev = player;
		player = player->next;
	}
	arena->last_player = player;
}
