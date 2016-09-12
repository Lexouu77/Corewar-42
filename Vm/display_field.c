/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:47:33 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/12 19:01:04 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_fg(int owner)
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

static void	display_bg(int owner, int live_value)
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
	if (live_value != 1)
		ft_printf("%s", "\x1b[30m");
}

static void	display_color(t_vm_data *arena, int owner, int index)
{
	if (arena->fresh_field[index])
		ft_printf("%s", ANSI_BOLD);
	if (arena->process_field[index] && arena->field[index] == 1)
		ft_printf("%s%s", ANSI_BOLD, ANSI_FG_WHITE);
	if (arena->process_field[index])
		display_bg(owner, arena->field[index]);
	else
		display_fg(owner);
	if ((index + 1) % (32 * 2) == 0 && index != 0)
	{
		if (owner == 0)
			ft_printf("%s%[[SP_RST]02x", "\x1b[2m", arena->field[index]);
		else
			ft_printf("%[[SP_RST]02x", arena->field[index]);
		display_info(arena, index, 0);
	}
	else if (owner == 0)
		ft_printf("%s%[[SP_RST]02x ", "\x1b[2m", arena->field[index]);
	else
		ft_printf("%[[SP_RST]02x ", arena->field[index]);
}

void		display_field(t_vm_data *arena)
{
	int		i;

	i = -1;
	ft_screenclr();
	ft_printf("\n\n");
	arena->modulo = 0;
	while (++i < MEM_SIZE)
	{
		if (arena->color)
		{
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
