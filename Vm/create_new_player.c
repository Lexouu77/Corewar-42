/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:21:38 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/13 17:55:48 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Create a new player, return an already malloced node with his desired number
** and his filename
*/

t_player		*create_new_player(int desired_number, char *file)
{
	t_player	*player;

	player = ft_memalloc(sizeof(t_player));
	if (desired_number > MAX_PLAYERS || desired_number < 1)
		player->desired_number = -1;
	else
		player->desired_number = desired_number;
	player->filename = ft_strdup(file);
	return (player);
}
