/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 22:14:29 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 19:29:04 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

#define PC player->comment
#define PN player->name

void			display_winner(t_vm_data *arena)
{
	const t_player	*player = get_winner(arena);

	if (arena->log_file)
		return ((void)ft_printf_fd(arena->fd, " %s (%s)!\n ", PN, PC));
	ft_printf("The winner is : ");
	if (player->number_of_player % 4 == 1)
		ft_printf(" %[[FG_GRE,SP_RST]s", player->name);
	else if (player->number_of_player % 4 == 2)
		ft_printf(" %[[FG_BLU,SP_RST]s", player->name);
	else if (player->number_of_player % 4 == 3)
		ft_printf(" %[[FG_RED,SP_RST]s", player->name);
	else if (player->number_of_player % 4 == 0)
		ft_printf(" %[[FG_CYA,SP_RST]s", player->name);
	else
		ft_printf(" %s", player->name);
	if (player->number_of_player % 4 == 1)
		ft_printf(" (%[[BG_GRE,SP_RST]s)!\n", player->comment);
	else if (player->number_of_player % 4 == 2)
		ft_printf(" (%[[BG_BLU,SP_RST]s)!\n", player->comment);
	else if (player->number_of_player % 4 == 3)
		ft_printf(" (%[[BG_RED,SP_RST]s)!\n", player->comment);
	else if (player->number_of_player % 4 == 0)
		ft_printf(" (%[[BG_CYA,SP_RST]s)!\n", player->comment);
	else
		ft_printf(" (%s)!\n", player->comment);
}
