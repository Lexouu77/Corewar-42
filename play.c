/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:32:25 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/23 20:11:13 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

extern t_op g_op_tab[];

static void	dump(t_vm_data *arena)
{
	display_field(arena);
	exit(0);
}

static void	dump_and_wait(t_vm_data *arena)
{
	char	c[4096];

	if (arena->cycles == 0)
		return ;
	display_field(arena);
	ft_printf("Press a key to continue.\n");
//	getchar();
	read(1, &c, 4096);
}

int		is_someone_alive(t_vm_data *arena)
{
	t_player	*player;
	int			alive;

	alive = 0;
	player = arena->players;
	while (player)
	{
		if (player->alive)
			alive = 1;
		player = player->next;
	}
	if (!alive)
	{
		player = arena->players;
		while (player)
		{
			player->to_kill = 1;
			player = player->next;
		}
		kill_player(arena);
		return (0);
	}
	check_period(arena);
	kill_player(arena);
	return (1);
}

void		set_players_in_game(t_vm_data *arena)
{
	t_player	*player;

	set_last_player(arena);
	player = arena->players;
	while (player && player->next)
	{
		player->last_process = player->process;
		player->still_in_game = 1;
		player->number_of_process++;
		player = player->next;
	}
	player->last_process = player->process;
	player->still_in_game = 1;
	player->number_of_process++;
	arena->last_player = player;
	arena->winner = arena->last_player->number_of_player;
	arena->next_cycle_check = arena->cycles_to_die;
	if ((arena->verbosity & 2) == 2)
		ft_printf_fd(arena->fd, "First check at cycle : %d\n",
				arena->next_cycle_check);
}

void			play(t_vm_data *arena)
{
	set_players_in_game(arena);
	while (1)
	{
		if ((arena->graph && !arena->pause) || !arena->graph)
		{
			//refresh_fresh_field(arena);
			arena->cycles++;
			increment_waiting_time(arena);
			check_instruction_from_proc(arena);
			execute_instruction(arena);
			if (arena->dump && arena->cycles % arena->cycles_to_dump == 0)
				dump(arena);
			if (arena->loop_dump && arena->cycles % arena->cycles_to_loop_dump
					== 0)
					dump_and_wait(arena);
//			if (arena->graph)
//				display_graphic(arena); // add un sleep dedans + faire un clear du screen;
			if (arena->cycles == arena->next_cycle_check)
				if (!is_someone_alive(arena))
					break ;
		}
//		if (arena->graph)
//			check_pause();
	}
}
