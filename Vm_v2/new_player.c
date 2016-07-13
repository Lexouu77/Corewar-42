/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:21:38 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/09 06:13:23 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Create a new player, return an already malloced node with his desired number
** and his filename
*/

t_player		*new_player(int desired_number, char *file)
{
	t_player	*player;

	if (!(player = (t_player *)ft_memalloc(sizeof(t_player))))
		ft_malloc_error();
	player->number_of_player = desired_number;
	player->filename = ft_strdup(file);
	return (player);
}
