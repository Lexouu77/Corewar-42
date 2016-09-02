/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 05:26:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/02 08:34:10 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		kill_player(t_vm_data *arena)
{
	t_player	*player;

	player = arena->players;
	while (player)
	{
		if (player->filename)
			free(player->filename);
		player = player->next;
	}
}
