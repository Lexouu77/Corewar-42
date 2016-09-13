/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_header.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 16:40:45 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/12 19:32:57 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	check_header_error(t_header header, char *file, int fd)
{
	int		x;

	if (!(read(fd, &x, 4)))
		return (display_error("Missing instructions", file));
	byte_swap(&header.magic, 4);
	byte_swap(&header.prog_size, 4);
	if (header.magic != COREWAR_EXEC_MAGIC)
		return (display_error("Wrong COREWAR_EXEC_MAGIC", file));
	if (!ft_strlen(header.prog_name))
		return (display_error("Missing prog_name", file));
	if (!header.prog_size)
		return (display_error("Prog_size is null", file));
	if (!ft_strlen(header.comment))
		return (display_error("Missing comment", file));
	if (header.prog_size > CHAMP_MAX_SIZE)
		return (display_error("Prog_size bigger than CHAMP_MAX_SIZE", file));
	return (1);
}

void		check_file_header(t_vm_data *arena)
{
	t_player	*players;
	t_header	header;
	int			fd;

	players = arena->players;
	while (players)
	{
		players->validity = 1;
		if ((fd = open(players->filename, O_RDONLY)) == -1)
		{
			display_error("Couldn't open the file.", players->filename);
			players->validity = 0;
		}
		ft_bzero(&header, sizeof(t_header));
		if (players->validity && !read(fd, &header, sizeof(t_header)))
		{
			display_error("Missing header.", players->filename);
			players->validity = 0;
		}
		if (players->validity && !check_header_error(header, players->filename,
					fd))
			players->validity = 0;
		close(fd);
		players = players->next;
	}
}
