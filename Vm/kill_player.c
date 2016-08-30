/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 05:26:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/30 21:44:22 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"



void		kill_player(t_vm_data *arena)
{
	t_player	*player;

	player = arena->players;
	while (player)
	{
			/*	display_kill_process(process, arena, player);
				tmp = process;
				process = process->next;
				free(tmp->reg);
				free(tmp);*/
		if (player->filename)
			free(player->filename);
	//	if (player->comment)
	//		free(player->comment);
		player = player->next;
	}
}
//free les player apres avoir afficher.
