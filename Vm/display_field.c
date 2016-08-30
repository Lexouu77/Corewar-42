/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:47:33 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/30 21:39:23 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_color(int value, int owner, int proc, int index)
{
	proc++;
	if ((index + 1) % (32 * 2) == 0 && index != 0)
	{
/*		if (proc == 1)
			ft_printf("%s", ANSI_BG_GREEN);
		if (proc == 2)
			ft_printf("%s", ANSI_BG_BLUE);
		if (proc == 3)
			ft_printf("%s", ANSI_BG_RED);
		if (proc == 4)
			ft_printf("%s", ANSI_BG_CYAN);
*/		if (owner % 4 == 1)
			ft_printf("%[[FG_GRE,SP_RST]02x\n", value);
		else if (owner % 4 == 2)
			ft_printf("%[[FG_BLU,SP_RST]02x\n", value);
			else if (owner % 4 == 3)
			ft_printf("%[[FG_RED,SP_RST]02x\n", value);
		else if (owner % 4 == 0)
			ft_printf("%[[FG_CYA,SP_RST]02x\n", value);
	}
	else
	{
/*		if (proc == 1)
			ft_printf("%s", ANSI_BG_GREEN);
		if (proc == 2)
			ft_printf("%s", ANSI_BG_BLUE);
		if (proc == 3)
			ft_printf("%s", ANSI_BG_RED);
		if (proc == 4)
			ft_printf("%s", ANSI_BG_CYAN);
*/		if (owner % 4 == 1)
			ft_printf("%[[FG_GRE,SP_RST]02x ", value);
		else if (owner % 4 == 2)
			ft_printf("%[[FG_BLU,SP_RST]02x ", value);
		else if (owner % 4 == 3)
			ft_printf("%[[FG_RED,SP_RST]02x ", value);
		else if (owner % 4 == 0)
			ft_printf("%[[FG_CYA,SP_RST]02x ", value);
	}
}

void		display_field(t_vm_data *arena)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (arena->color && arena->color_field[i])
			display_color(arena->field[i], arena->color_field[i], arena->process_field[i], i);
		else
		{
			if ((i + 1) % (32 * 2) == 0 && i != 0)
				ft_printf("%02x\n", arena->field[i]);
			else
				ft_printf("%02x ", arena->field[i]);
		}
	}
}
