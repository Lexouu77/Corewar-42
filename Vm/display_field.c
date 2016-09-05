/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:47:33 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/05 04:16:23 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

 // TODO :keyhooks avec les termcaps pour monter / diminuer le nb de cycles qu'on avance.
// change printf with buffer and flush.

static char	*get_color(t_vm_data *arena, int number)
{
	if (number == 1 || (arena->modulo / 4 + 1 == 1 && !number))
		return (ANSI_FG_GREEN);
	if (number == 2 || (arena->modulo / 4 + 1 == 2 && !number))
		return (ANSI_FG_BLUE);
	if (number == 3 || (arena->modulo / 4 + 1 == 3 && !number))
		return (ANSI_FG_RED);
	return (ANSI_FG_CYAN);
}

static char	*get_name(t_vm_data *arena)
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

static int	get_last_live(t_vm_data *arena)
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

static int	get_period_live(t_vm_data *arena)
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

static void	display_minus(t_vm_data *arena, t_player *player, int total)
{
	int	i;
	int	loop;

	loop = player->period_live_number * 50 / total;
	i = -1;
	ft_printf("%s", get_color(arena, player->number_of_player));
	while(++i < (int)loop)
		ft_printf("-");
}

static void	display_breakdown(t_vm_data *arena)
{
	t_player	*player;
	int			total_lives;

	total_lives = 0;
	player = arena->players;
	while (player)
	{
		total_lives += player->period_live_number;
		player = player->next;
	}
	if (!total_lives)
		return ((void)ft_printf("\t\t%s[--------------------------------------------------]", "\x1b[2m"));
	player = arena->players;
	ft_printf("\t\t%s[", "\x1b[2m");
	while (player)
	{
		if (player->period_live_number)
			display_minus(arena, player, total_lives);
		player = player->next;
	}
	ft_printf("%s%s]", "\x1b[0m", "\x1b[2m");
}

static void	display_player(t_vm_data *arena, int i, int color)
{
	if (i >= 1407 + arena->number_of_players * 256)
		return ;
	arena->modulo++;
	if (i < 1407 + arena->number_of_players * 256 && arena->modulo % 4)
	{
		if (arena->modulo % 4 == 1 && color)
			ft_printf("\t\tPlayer number %d : %s%s", arena->modulo / 4 + 1,
					get_color(arena, 0), get_name(arena));
		if (arena->modulo % 4 == 1 && !color)
			ft_printf("\t\tPlayer number %d : %s", arena->modulo / 4 + 1,
					get_name(arena));
		if (arena->modulo % 4 == 2)
			ft_printf("\t\t  Last live : %21d", get_last_live(arena));
		if (arena->modulo % 4 == 3)
			ft_printf("\t\t  Lives in current period : %7d",
					get_period_live(arena));
	}
}

static void	display_info(t_vm_data *arena, int i, int d_value)
{
	if (d_value)
		ft_printf("%[[SP_RST]02x", arena->field[i]);
	ft_printf("%s", ANSI_BOLD);
	if (i == 191)
		ft_printf("\t\tCycles : %s%d", "\x1b[3m", arena->cycles);
	else if (arena->loop_dump && i == 63)
		ft_printf("\t\tCycle speed : %d/%C", arena->cycles_to_loop_dump, 9166);
	else if (i == 319)
		ft_printf("\t\tProcesses : %d", arena->number_of_process);
	else if (i == 447)
		ft_printf("\t\tPeriod number : %d", arena->number_of_checks);
	else if (i == 575)
		ft_printf("\t\tNext Check : %d", arena->next_cycle_check);
	else if (i == 703)
		ft_printf("\t\tCYCLE %C : %d", 916, arena->cycle_delta);
	else if (i == 831)
		ft_printf("\t\tCYCLE TO %C : %d", 9760, arena->cycles_to_die);
	else if (i == 959)
		ft_printf("\t\tNBR_LIVE : %d", NBR_LIVE);
	else if (i == 1087)
		ft_printf("\t\tMAX_CHECKS : %d", MAX_CHECKS);
	else if (i == 1215)
		ft_printf("\t\tLive breakdown for this period :");
	else if (i == 1279)
		display_breakdown(arena);
	else if (i >= 1407 && (((i - 1407) % 64) == 0)) // %256
		display_player(arena, i, arena->color);
	ft_printf("%[[SP_RST]c", '\n');
}

static void	display_color(t_vm_data *arena, int owner, int index)
{
	if (arena->fresh_field[index])
		ft_printf("%s", ANSI_BOLD);
	if (arena->process_field[index] && arena->field[index] == 1)
		ft_printf("%s%s", ANSI_BOLD, ANSI_FG_WHITE);
	if (arena->process_field[index])
	{
		if (owner == 0)
			ft_printf("%s", ANSI_BG_WHITE);
		else if (owner % 4 == 1)
			ft_printf("%s", ANSI_BG_GREEN);
		else if (owner % 4 == 2)
			ft_printf("%s", ANSI_BG_BLUE);
		else if (owner % 4 == 3)
			ft_printf("%s", ANSI_BG_RED);
		else if (owner % 4 == 0 && owner != 0)
			ft_printf("%s", ANSI_BG_CYAN);
		if (arena->field[index] != 1)
			ft_printf("%s", "\x1b[30m");
	}
	else
	{
		if (owner % 4 == 1)
			ft_printf("%s", ANSI_FG_GREEN);
		else if (owner % 4 == 2)
			ft_printf("%s", ANSI_FG_BLUE);
		else if (owner % 4 == 3)
			ft_printf("%s", ANSI_FG_RED);
		else if (owner % 4 == 0 && owner != 0)
			ft_printf("%s", ANSI_FG_CYAN);
	}
	if ((index + 1) % (32 * 2) == 0 && index != 0)
	{
		ft_printf("%[[SP_RST]02x", arena->field[index]);
		display_info(arena, index, 0);
	}
	else
		ft_printf("%[[SP_RST]02x ", arena->field[index]);
}

void		display_field(t_vm_data *arena)
{
	int		i;

	i = -1;
	ft_screenclr();
	arena->modulo = 0;
	while (++i < MEM_SIZE)
	{
		if (arena->color)
		{
//			if (arena->process_field[i])
//				ft_printf("%s", ANSI_REVERSE_COLOR);
			display_color(arena, arena->color_field[i], i);
		}
		else
		{
			if ((i + 1) % (32 * 2) == 0 && i != 0)
				display_info(arena, i, 1);
			else
				ft_printf("%02x ", arena->field[i]);
		}
	}
}
