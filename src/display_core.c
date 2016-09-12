/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjivas <adjivas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 03:22:18 by adjivas           #+#    #+#             */
/*   Updated: 2016/09/12 05:08:22 by adjivas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	display_info_player(t_vm_data *arena)
{
	t_player *player;

	player = arena->players;
	ft_printf("\x1B[80;5H");
	while (player)
	{
		ft_printf("%s", player->name);
		if ((player = player->next) != NULL)
			ft_printf(" · ");
	}
	ft_printf(".");
}

void	display_info(t_vm_data *arena)
{
	ft_printf("%s[Cycles : %d]", "\x1B[3;75H", arena->cycles);
	ft_printf(" [Cycle speed : %d/9166]", arena->cycles_to_loop_dump);
	ft_printf("%s[Nbr Players : %d]", "\x1B[4;75H", arena->number_of_players);
	ft_printf(" [Period number : %d]", arena->number_of_checks);
	ft_printf("%s[Next Check : %d]", "\x1B[5;75H", arena->next_cycle_check);
	ft_printf(" [CYCLE %C : %d]", 916, arena->cycle_delta);
	ft_printf("%s[MAX_CHECKS : %d]", "\x1B[6;75H", MAX_CHECKS);
	ft_printf(" [NBR_LIVE : %d]", NBR_LIVE);
}
