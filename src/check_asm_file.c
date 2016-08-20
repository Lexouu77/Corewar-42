/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asm_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 18:40:55 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/14 22:27:32 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	check_asm_presence(void)
{
	if (access("../Asm/", F_OK) == -1)
		return (display_warning("Asm directory was not found.", NULL));
	if (access("../Asm/asm", F_OK) == -1)
		return (display_warning("Asm binary was not found.", NULL));
	if (access("../Asm/asm", X_OK) == -1)
		return (display_warning("Asm binary has no execution rights.", NULL));
	return (1);
}

static int	is_there_a_s_file(t_vm_data *arena)
{
	t_player	*players;

	players = arena->players;
	while (players)
	{
		if (is_a_s_file(players->filename))
			return (1);
		players = players->next;
	}
	return (0);
}

void		check_asm_file(t_vm_data *arena)
{
	t_player	*players;
	int			is_asm_here;

	if (!is_there_a_s_file(arena))
		return ;
	is_asm_here = check_asm_presence();
	players = arena->players;
	if (!is_asm_here)
		while (players)
		{
			if (is_a_s_file(players->filename))
				players->validity = 0;
			else
				players->validity = 1;
			players = players->next;
		}
	if (!is_asm_here)
		return (delete_invalid_players(arena));
	while (players)
	{
		if (is_a_s_file(players->filename))
			assemble_asm_file(players);
		players = players->next;
	}
	delete_invalid_players(arena);
}
