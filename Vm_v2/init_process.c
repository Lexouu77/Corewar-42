/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:20:33 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/13 10:42:32 by ahamouda         ###   ########.fr       */
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
	return (((MEM_SIZE) / (number )) * (player_number - 1));
}

void		init_process(t_vm_data *arena)
{
	t_player	*players;
	int			i;

	i = -1;
	players = arena->players;
	while (++i < 4 && players)
	{
		if (!(players->process = (t_proc *)ft_memalloc(sizeof(t_proc))))
			ft_malloc_error();
		if (!(players->process->reg =
					(int *)ft_memalloc(sizeof(int) * REG_NUMBER)))
			ft_malloc_error();
		players->process->number = arena->process_next_number++;
		players->process->father = players;
		players->process->reg[0] = players->number_of_player;
		players->process->owner = players->number_of_player;
		players->process->owner = players->number_of_player;
		players->process->pc = get_pc(arena->number_of_valid_player,
				players->number_of_player);
		players->validity = 1;
		players = players->next;
	}
}
 // add verbosity 8/16 : instructions -> "Procc n°x owned by player n°x did opcode n°x."
 // add un bonus qui fait une sortie dans un fichier avec printf_fd -> bonus -f add un int fd dans arena (vm.h) et le set a 0 ou a fg. disable color if fd != 0
