/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_of_players.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 06:28:34 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/13 10:30:16 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_player(t_vm_data *arena)
{
	t_player	*players;
	int			i;

	players = arena->players;
	i = -1;
	if (arena->number_of_valid_player)
		ft_printf("Players used in this session : \n");
	while (++i < 4 && players)
	{
		ft_printf("%[[FG_GRE,SP_RST]s", players->filename);
		if (i + 1 < 4 && players->next)
			ft_printf(" | ");
		players = players->next;
	}
	if (!players)
		return ((void)ft_printf("\n"));
	ft_printf("\nPlayers unused in this session : \n");
	while (players)
	{
		players->validity = 0;
		ft_printf("%[[FG_MAG,SP_RST]s", players->filename);
		if (players->next)
			ft_printf(" | ");
		players = players->next;
	}
}

void		get_number_of_players(t_vm_data *arena)
{
	t_player	*players;

	players = arena->players;
	while (players)
	{
		arena->number_of_valid_player++;
		players = players->next;
	}
	if (arena->number_of_valid_player > MAX_PLAYERS)
	{
		ft_printf("%[[FG_RED,SP_RST]s %[[FG_YEL,SP_RST]s", "WARNING", "->");
		ft_printf(" You have more than MAX_PLAYERS(%[[FG_RED,SP_RST]d)",
				MAX_PLAYERS);
		ft_printf(" valid players, number of valid players :");
		ft_printf(" [%[[FG_GRE,SP_RST]d] \n", arena->number_of_valid_player);
	}
	if (arena->number_of_valid_player)
	{
		display_player(arena);
		ft_printf("\n");
	}
}
