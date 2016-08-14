/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_players_in_field.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:52:03 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/14 21:17:32 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	stock_header(t_player *player, t_header *header)
{
	byte_swap(&header->magic, 4);
	byte_swap(&header->prog_size, 4);
	player->name = ft_strdup(header->prog_name);
	player->comment = ft_strdup(header->comment);
	player->bytes_size = header->prog_size;
}

void		set_players_in_field(t_vm_data *arena)
{
	t_player	*players;
	int			fd;
	t_header	header;

	players = arena->players;
	while (players)
	{
		if ((fd = open(players->filename, O_RDONLY)) == -1)
		{
			display_error("Couldn't open the file.", players->filename);
			players = players->next;
			continue ;
		}
		if (!read(fd, &header, sizeof(t_header)))
		{
			display_error("Couldn't read the header.", players->filename);
			close(fd);
			players = players->next;
			continue ;
		}
		stock_header(players, &header);
		fill_field(arena, players, header.prog_size, fd);
		close(fd);
		players = players->next;
	}
}
