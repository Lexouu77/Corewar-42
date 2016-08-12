/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduce_players.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:12:27 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/12 16:55:37 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	get_definite_number_of_players(t_vm_data *arena)
{
	t_player	*player;
	int			n;

	n = 0;
	player = arena->players;
	while (player)
	{
		player = player->next;
		n++;
	}
	return (n);
}

static void	display_name(t_player *player)
{
	if (player->number_of_player == 1)
		ft_printf("aka %[[FG_GRE,SP_RST]s", player->name);
	else if (player->number_of_player == 2)
		ft_printf("aka %[[FG_BLU,SP_RST]s", player->name);
	else if (player->number_of_player == 3)
		ft_printf("aka %[[FG_RED,SP_RST]s", player->name);
	else if (player->number_of_player == 4)
		ft_printf("aka %[[FG_CYA,SP_RST]s", player->name);
	else
		ft_printf("aka %s", player->name);
}

static void	display_comment(t_player *player)
{
	if (player->number_of_player == 1)
		ft_printf(" (%[[BG_GRE,SP_RST]s)\n", player->comment);
	else if (player->number_of_player == 2)
		ft_printf(" (%[[BG_BLU,SP_RST]s)\n", player->comment);
	else if (player->number_of_player == 3)
		ft_printf(" (%[[BG_RED,SP_RST]s)\n", player->comment);
	else if (player->number_of_player == 4)
		ft_printf(" (%[[BG_CYA,SP_RST]s)\n", player->comment);
	else
		ft_printf(" (%s)\n", player->comment);
}

void		introduce_players(t_vm_data *arena)
{
	int			i;
	t_player	*player;

	player = arena->players;
	arena->number_of_players = get_definite_number_of_players(arena);
	i = -1;
	if (arena->number_of_players == 1)
		ft_printf("Today, we have only one challenger!\n");
	else
		ft_printf("Today, we have %d challengers!\n", arena->number_of_players);
	while (++i < arena->number_of_players && player)
	{
		if (i == 0)
			ft_printf("Our first player, weighing %d", player->bytes_size);
		else if (i == 1)
			ft_printf("Our second player, weighing %d", player->bytes_size);
		else if (i == 2)
			ft_printf("Our third player, weighing %d", player->bytes_size);
		else if (i == 3)
			ft_printf("Our fourth player, weighing %d", player->bytes_size);
		else
			ft_printf("Our player number %d, weighing %d", i + 1, player->bytes_size);
		ft_printf(" bytes ");
		display_name(player);
		display_comment(player);
		player = player->next;
	}
}
