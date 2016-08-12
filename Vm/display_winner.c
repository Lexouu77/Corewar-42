/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 22:14:29 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/11 22:14:46 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			display_winner(t_vm_data *arena)
{
	t_player	*player;

	player = get_winner(arena);
	ft_printf("The winner is : ");
	if (player->number_of_player == 1)
		ft_printf(" %[[FG_GRE,SP_RST]s", player->name);
	if (player->number_of_player == 2)
		ft_printf(" %[[FG_BLU,SP_RST]s", player->name);
	if (player->number_of_player == 3)
		ft_printf(" %[[FG_RED,SP_RST]s", player->name);
	if (player->number_of_player == 4)
		ft_printf(" %[[FG_CYA,SP_RST]s", player->name);
	if (player->number_of_player == 1)
		ft_printf(" (%[[BG_GRE,SP_RST]s)!\n", player->comment);
	if (player->number_of_player == 2)
		ft_printf(" (%[[BG_BLU,SP_RST]s)!\n", player->comment);
	if (player->number_of_player == 3)
		ft_printf(" (%[[BG_RED,SP_RST]s)!\n", player->comment);
	if (player->number_of_player == 4)
		ft_printf(" (%[[BG_CYA,SP_RST]s)!\n", player->comment);
}
