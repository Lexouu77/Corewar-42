/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_players_in_field.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:52:03 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/14 10:06:29 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

extern t_op g_op_tab[];

static int	read_op_code(t_vm_data *arena, t_instr *instr,
		t_player *player, int *size)
{
	if (!read(instr->fd, &instr->op_code, 1))
		return (0);
	arena->field[player->process->pc + instr->i] = instr->op_code;
	arena->color_field[player->process->pc + instr->i] =
		player->number_of_player;
	instr->i++;
	*size = *size - 1;
	instr->number_of_args = g_op_tab[instr->op_code - 1].arg_number;
	return (1);
}

//#include <stdio.h>

static int	read_format(t_vm_data *arena, t_instr *instr, t_player *player,
		int *size)
{
	if (!g_op_tab[instr->op_code - 1].byte_param)
		return (1);
	instr->format = 0x00;
	if (!read(instr->fd, &instr->format, 1))
		return (0);
//	fprintf(stderr, "format: : '%C' = %d = 0x%x\n", (unsigned char)instr->format, (int)instr->format, (unsigned int)instr->format);
	arena->field[player->process->pc + instr->i] = (int)instr->format;
	arena->color_field[player->process->pc + instr->i] =
		player->number_of_player;
	instr->i++;
	*size = *size - 1;
	return (1);
}

static void	get_tmp_args_size(t_vm_data *arena, int format, int n_arg, int op_c)
{
	int	shift;
	int	i;

	if (!(arena->tmp_args_value = (int*)ft_memalloc(n_arg * sizeof(int))))
		ft_malloc_error();
	i = -1;
	while (++i < n_arg)
	{
		shift = 6 - 2 * i;
		if (((format >> shift) & 0x3) == REG_CODE)
			arena->tmp_args_value[i] = 1;
		if (((format >> shift) & 0x3) == IND_CODE)
			arena->tmp_args_value[i] = IND_SIZE;
		if (((format >> shift) & 0x3) == DIR_CODE)
			arena->tmp_args_value[i] =
				(g_op_tab[op_c - 1].byte_dir) ? IND_SIZE : DIR_SIZE;
	}
}

static int	read_args_value(t_vm_data *arena, t_instr *instr, t_player *player,
		int *size)
{
	int		i;
	int		tmp;

	if (!g_op_tab[instr->op_code - 1].byte_param)
		return (1);
	i = -1;
	get_tmp_args_size(arena, instr->format, instr->number_of_args,
			instr->op_code);
	while (++i < instr->number_of_args)
	{
		if (!(read(instr->fd, &tmp, arena->tmp_args_value[i])))
			return (0); //add free ^
		byte_swap(&tmp, arena->tmp_args_value[i]);
		if (arena->tmp_args_value[i] == 2)
		{
			arena->field[player->process->pc + instr->i] = (tmp >> 8) & 0xFF;
			arena->field[player->process->pc + ++instr->i] = tmp & 0xFF;
		}
		else if (arena->tmp_args_value[i] == 4)
		{
			arena->field[player->process->pc + instr->i] = (tmp >> 24) & 0xFF;
			arena->field[player->process->pc + ++instr->i] = (tmp >> 16) & 0xFF;
			arena->field[player->process->pc + ++instr->i] = (tmp >> 8) & 0xFF;
			arena->field[player->process->pc + ++instr->i] = tmp & 0xFF;
		}
		else
			arena->field[player->process->pc + instr->i] = tmp & 0xFF;
		instr->i++;
		*size = *size - arena->tmp_args_value[i];
	}
	free(arena->tmp_args_value);
	return (1);
}

static int read_fixed_args_value(t_vm_data *arena, t_instr *instr,
		t_player *player, int *size)
{
	int			tmp;
	const int	direct_size = (g_op_tab[instr->op_code - 1].byte_dir) ?
		IND_SIZE : DIR_SIZE;

	if (g_op_tab[instr->op_code - 1].byte_param)
		return (1);
	if (!(read(instr->fd, &tmp, direct_size)))
		return (0);
	byte_swap(&tmp, direct_size);
	if (direct_size == 2)
	{
		arena->field[player->process->pc + instr->i] = (tmp >> 8) & 0xFF;
		arena->field[player->process->pc + ++instr->i] = tmp & 0xFF;
	}
	else if (direct_size == 4)
	{
		arena->field[player->process->pc + instr->i] = (tmp >> 24) & 0xFF;
		arena->field[player->process->pc + ++instr->i] = (tmp >> 16) & 0xFF;
		arena->field[player->process->pc + ++instr->i] = (tmp >> 8) & 0xFF;
		arena->field[player->process->pc + ++instr->i] = tmp & 0xFF;
	}
	else
		arena->field[player->process->pc + instr->i] = tmp & 0xFF;
	instr->i++;
	*size = *size - direct_size;
	return (1);
}

static void	read_instructions(t_vm_data *arena, t_player *player,
		int prog_size, int fd)
{
	int			size;
	t_instr		instr;

	size = prog_size;
	instr.i = 0;
	instr.fd = fd;
	while (size)
	{
		if (!read_op_code(arena, &instr, player, &size))
			break ;
		if (!read_format(arena, &instr, player, &size))
			break ;
		if (!read_args_value(arena, &instr, player, &size))
			break ;
		if (!read_fixed_args_value(arena, &instr, player, &size))
			break ;
	}
}

static void	stock_header(t_player *player, t_header *header)
{
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
			exit(-1);
		}
		if (!read(fd, &header, sizeof(t_header)))
		{
			display_error("Couldn't read the header.", players->filename);
			exit(-1);
		}
		byte_swap(&header.magic, 4);
		byte_swap(&header.prog_size, 4);
		stock_header(players, &header);
		read_instructions(arena, players, header.prog_size, fd);
		close(fd);
		players = players->next;
	}
}

// add le color field et process field .
