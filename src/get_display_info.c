/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_display_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 18:36:09 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/12 18:43:54 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	*get_color(t_vm_data *arena, int number)
{
	if (number == 1 || (arena->modulo / 4 + 1 == 1 && !number))
		return (ANSI_FG_GREEN);
	if (number == 2 || (arena->modulo / 4 + 1 == 2 && !number))
		return (ANSI_FG_BLUE);
	if (number == 3 || (arena->modulo / 4 + 1 == 3 && !number))
		return (ANSI_FG_RED);
	return (ANSI_FG_CYAN);
}

char	*get_name(t_vm_data *arena)
{
	t_player	*player;
	const int	mod = arena->modulo / 4 + 1;

	player = arena->players;
	while (player)
	{
		if (mod == player->number_of_player)
			break ;
		player = player->next;
	}
	return (player->name);
}

int		get_last_live(t_vm_data *arena)
{
	t_player	*player;
	const int	mod = arena->modulo / 4 + 1;

	player = arena->players;
	while (player)
	{
		if (mod == player->number_of_player)
			break ;
		player = player->next;
	}
	return (player->cycle_of_last_live);
}

int		get_period_live(t_vm_data *arena)
{
	t_player	*player;
	const int	mod = arena->modulo / 4 + 1;

	player = arena->players;
	while (player)
	{
		if (mod == player->number_of_player)
			break ;
		player = player->next;
	}
	return (player->period_live_number);
}
