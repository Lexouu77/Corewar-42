/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:50:31 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/12 16:19:25 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	add_player(t_vm_data *arena, int desired_number, char *file)
{
	t_player	*p_player;

	p_player = arena->players;
	while (p_player->next)
		p_player = p_player->next;
	p_player->next = create_new_player(desired_number, file);
}
