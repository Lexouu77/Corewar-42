/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 18:28:10 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/12 18:42:09 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define BRKDNW "[--------------------------------------------------]"

static void	display_minus(t_vm_data *arena, t_player *player, int total)
{
	int	i;
	int	loop;

	loop = player->period_live_number * 50 / total;
	i = -1;
	ft_printf("%[[SP_BOL]s", get_color(arena, player->number_of_player));
	while (++i < loop)
		ft_printf("-");
	ft_printf("%s", ANSI_RESET);
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
		return ((void)ft_printf("\t\t%s%s", "\x1b[2m", BRKDNW));
	player = arena->players;
	ft_printf("\t\t%s[%s", "\x1b[2m", ANSI_RESET);
	while (player)
	{
		if (player->period_live_number)
			display_minus(arena, player, total_lives);
		player = player->next;
	}
	ft_printf("%s%s]", "\x1b[0m", "\x1b[2m");
}

static void	display_more_info(t_vm_data *arena, int i)
{
	if (i == 191)
		ft_printf("\t\tCycles : %s%d", "\x1b[3m", arena->cycles);
	else if (arena->loop_dump && i == 63)
		ft_printf("\t\tCycle speed : %d/%C", arena->cycles_to_loop_dump, 9166);
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

void		display_info(t_vm_data *arena, int i, int d_value)
{
	if (d_value)
		ft_printf("%[[SP_RST]02x", arena->field[i]);
	ft_printf("%s", ANSI_BOLD);
	display_more_info(arena, i);
	if (i == 319)
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
	else if (i >= 1407 && (((i - 1407) % 64) == 0))
		display_player(arena, i, arena->color);
	ft_printf("%[[SP_RST]c", '\n');
}
