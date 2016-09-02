/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:47:33 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/02 09:14:53 by ahamouda         ###   ########.fr       */
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

static void	display_color(int value, int owner, int index, int fresh_field)
{
	if (fresh_field)
		ft_printf("%s", ANSI_BOLD);
	if ((index + 1) % (32 * 2) == 0 && index != 0)
	{
		if (!owner)
			return ((void)ft_printf("%[[SP_RST]02x\n", value));
		if (owner % 4 == 1)
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
		if (!owner)
			return ((void)ft_printf("%[[SP_RST]02x ", value));
		display_value(owner, value);
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
				ft_printf("%s", ANSI_BG_CYAN);
			display_color(arena->field[i], arena->color_field[i], i,
					arena->fresh_field[i]);
		}
		else
		{
			if ((i + 1) % (32 * 2) == 0 && i != 0)
				ft_printf("%02x\n", arena->field[i]);
			else
				ft_printf("%02x ", arena->field[i]);
		}
	}
}
