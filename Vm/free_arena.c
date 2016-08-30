/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 22:15:37 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/30 21:57:15 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			free_arena(t_vm_data *arena)
{
	t_player	*player;

	player = arena->players;
	while (player)
	{
		free(player->name);
		free(player->comment);
		player = player->next;
	}
	if (arena->log_file)
		close(arena->fd);
	free(arena->field);
	free(arena->color_field);
	free(arena->process_field);
	free(arena->fresh_field);
}
