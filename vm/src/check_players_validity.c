/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_players_validity.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 22:29:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/12 16:36:37 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	is_valid(char *s)
{
	const int	len = ft_strlen(s);

	if ((len > 4 && !ft_strcmp(s + len - 4, ".cor")) ||
			(len > 2 && !ft_strcmp(s + len - 2, ".s")))
		return (1);
	return (0);
}

void		check_players_validity(t_vm_data *arena)
{
	t_player	*p_player;

	p_player = arena->players;
	while (p_player)
	{
		if (!is_valid(p_player->filename))
		{
			p_player->validity = 0;
			if (p_player->filename[0] == '-')
				display_error("Unknown flag.", p_player->filename);
			else
				display_error("Invalid filename.", p_player->filename);
		}
		else if (!is_file_valid(p_player->filename))
			p_player->validity = 0;
		else
			p_player->validity = 1;
		p_player = p_player->next;
	}
}
