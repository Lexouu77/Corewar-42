/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:47:33 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/05 00:50:14 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_value(int owner, int value)
{
	if (owner % 4 == 1)
		ft_printf("%[[FG_GRE,SP_RST]02x ", value);
	else if (owner % 4 == 2)
		ft_printf("%[[FG_BLU,SP_RST]02x ", value);
	else if (owner % 4 == 3)
		ft_printf("%[[FG_RED,SP_RST]02x ", value);
	else if (owner % 4 == 0)
		ft_printf("%[[FG_CYA,SP_RST]02x ", value);
}

 // TODO : Breakdown + champion

//change 1215 by a proper value

static void	display_player(t_vm_data *arena, int i, int color)
{
	if ((i - 1215) % 256)
		return ;
}

static void	display_info(t_vm_data *arena, int i, int d_value)
{
	if (d_value)
		ft_printf("%[[SP_RST]02x", arena->field[i]);
	ft_printf("%s", ANSI_BOLD);
	if (i == 191)
		ft_printf("\t\tCycles : %d", arena->cycles);
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
//	else if (i >= 1215 && (((i - 1215) % 64) == 0)) // %256
//		display_player(arena, i, arena->color);
	ft_printf("%[[SP_RST]c", '\n');
}

static void	display_color(t_vm_data *arena, int owner, int index)
{
	if (arena->fresh_field[index])
		ft_printf("%s", ANSI_BOLD);
	if ((index + 1) % (32 * 2) == 0 && index != 0)
	{
		if (!owner)
			ft_printf("%[[SP_RST]02x", arena->field[index]);
		if (owner % 4 == 1)
			ft_printf("%[[FG_GRE,SP_RST]02x", arena->field[index]);
		else if (owner % 4 == 2)
			ft_printf("%[[FG_BLU,SP_RST]02x", arena->field[index]);
		else if (owner % 4 == 3)
			ft_printf("%[[FG_RED,SP_RST]02x", arena->field[index]);
		else if (owner % 4 == 0 && owner != 0)
			ft_printf("%[[FG_CYA,SP_RST]02x", arena->field[index]);
		display_info(arena, index, 0);
	}
	else
	{
		if (!owner)
			return ((void)ft_printf("%[[SP_RST]02x ", arena->field[index]));
		display_value(owner, arena->field[index]);
	}
}

void		display_field(t_vm_data *arena)
{
	int		i;

	i = -1;
	ft_screenclr();
	while (++i < MEM_SIZE)
	{
		if (arena->color)
		{
			if (arena->process_field[i])
				ft_printf("%s", ANSI_BG_YELLOW);
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
