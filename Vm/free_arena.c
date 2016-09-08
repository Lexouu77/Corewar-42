/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 22:15:37 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/08 22:44:58 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			free_arena(t_vm_data *arena)
{
	t_player	*player;
	t_player	*tmp;
//	t_proc		*process;
//	t_proc		*tmp_proc;

	player = arena->players;
	while (player)
	{
		free(player->name);
		free(player->comment);
		tmp = player;
		player = player->next;
		free(tmp);
	}
//	process = arena->process;
//	while (process)
//	{
//	}
	if (arena->log_file)
		close(arena->fd);
	free(arena->field);
	free(arena->color_field);
	free(arena->process_field);
	free(arena->fresh_field);
}
