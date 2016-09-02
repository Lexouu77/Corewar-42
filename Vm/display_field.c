/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:47:33 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/02 03:46:08 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_color(int value, int owner, int proc, int index, int x)
{
	(void)proc;
	if (x)
		ft_printf("%s", ANSI_BOLD);
	if (proc)
		ft_printf("%s", ANSI_BG_CYAN);
	if ((index + 1) % (32 * 2) == 0 && index != 0)
	{
	/*	if (owner % 4 == 1 && proc == 1)
			ft_printf("%[[BG_GRE,SP_RST]02x\n", value);
		else if (owner % 4 == 2 && proc == 2)
			ft_printf("%[[BG_BLU,SP_RST]02x\n", value);
		else if (owner % 4 == 3 && proc == 3)
			ft_printf("%[[BG_RED,SP_RST]02x\n", value);
		else if (owner % 4 == 0 && proc == 4)
			ft_printf("%[[BG_CYA,SP_RST]02x\n", value);*/
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
/*		if (owner % 4 == 1 && proc == 1)
			ft_printf("%[[BG_GRE,SP_RST]02x ", value);
		else if (owner % 4 == 2 && proc == 2)
			ft_printf("%[[BG_BLU,SP_RST]02x ", value);
		else if (owner % 4 == 3 && proc == 3)
			ft_printf("%[[BG_RED,SP_RST]02x ", value);
		else if (owner % 4 == 0 && proc == 4)
			ft_printf("%[[BG_CYA,SP_RST]02x ", value);
	*/	if (!owner)
			return ((void)ft_printf("%[[SP_RST]02x ", value));
		if (owner % 4 == 1)
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
	//int		proc;
	//int		value;

	i = -1;
	ft_screenclr();
	while (++i < MEM_SIZE)
	{
		/*
		proc = arena->process_field[i];
		value = arena->field[i];
*/		if (arena->color /*&& arena->color_field[i]*/)
			display_color(arena->field[i], arena->color_field[i], arena->process_field[i], i, arena->fresh_field[i]);
/*		else if (arena->process_field[i])
		{
			if ((i + 1) % (32 * 2) == 0 && i != 0)
			{
				if (proc == 1)
					ft_printf("%[[BG_GRE,SP_RST]02x\n", value);
				else if (proc == 2)
					ft_printf("%[[BG_BLU,SP_RST]02x\n", value);
				else if (proc == 3)
					ft_printf("%[[BG_RED,SP_RST]02x\n", value);
				else if (proc == 4)
					ft_printf("%[[BG_CYA,SP_RST]02x\n", value);
			}
			else
			{
				if (proc == 1)
					ft_printf("%[[BG_GRE,SP_RST]02x ", value);
				else if (proc == 2)
					ft_printf("%[[BG_BLU,SP_RST]02x ", value);
				else if (proc == 3)
					ft_printf("%[[BG_RED,SP_RST]02x ", value);
				else if (proc == 4)
					ft_printf("%[[BG_CYA,SP_RST]02x ", value);
			}
		}*/
		else
		{
			if ((i + 1) % (32 * 2) == 0 && i != 0)
				ft_printf("%02x\n", arena->field[i]);
			else
				ft_printf("%02x ", arena->field[i]);
		}
	}
}
