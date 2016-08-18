/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:20:33 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/14 21:36:39 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	get_pc(int total_players, int player_number)
{
	int number;

	if (total_players >= MAX_PLAYERS)
		number = MAX_PLAYERS;
	else
		number = total_players;
	return (((MEM_SIZE) / (number)) * (player_number - 1));
}

void		init_process(t_vm_data *arena)
{
	t_player	*players;
	int			i;

	i = -1;
	players = arena->players;
	while (++i < MAX_PLAYERS && players)
	{
		players->process = ft_memalloc(sizeof(t_proc));
		players->process->reg = ft_memalloc(sizeof(int) * REG_NUMBER);
		players->process->number = arena->process_next_number++;
		players->process->father = players;
		players->process->reg[0] = players->number_of_player;
		players->process->owner = players->number_of_player;
		players->process->owner = players->number_of_player;
		players->process->pc = get_pc(arena->number_of_valid_player,
				players->number_of_player);
		arena->process_field[players->process->pc] = players->number_of_player;
		players->validity = 1;
		players = players->next;
	}
}
