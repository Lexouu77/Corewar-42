/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:47:33 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 19:28:38 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	display_color(int value, int owner, int index)
{
	if ((index + 1) % (32 * 2) == 0 && index != 0)
	{
		if (owner % 4 == 1)
			ft_printf("%[[BG_GRE,SP_RST]02x\n", value);
		else if (owner % 4 == 2)
			ft_printf("%[[BG_BLU,SP_RST]02x\n", value);
			else if (owner % 4 == 3)
			ft_printf("%[[BG_RED,SP_RST]02x\n", value);
		else if (owner % 4 == 0)
			ft_printf("%[[BG_CYA,SP_RST]02x\n", value);
	}
	else
	{
		if (owner % 4 == 1)
			ft_printf("%[[BG_GRE,SP_RST]02x ", value);
		else if (owner % 4 == 2)
			ft_printf("%[[BG_BLU,SP_RST]02x ", value);
			else if (owner % 4 == 3)
			ft_printf("%[[BG_RED,SP_RST]02x ", value);
		else if (owner % 4 == 0)
			ft_printf("%[[BG_CYA,SP_RST]02x ", value);
	}
}

void		display_field(t_vm_data *arena)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (arena->color && arena->color_field[i])
			display_color(arena->field[i], arena->color_field[i], i);
		else
		{
			if ((i + 1) % (32 * 2) == 0 && i != 0)
				ft_printf("%02x\n", arena->field[i]);
			else
				ft_printf("%02x ", arena->field[i]);
		}
	}
}

//Changer printf, retourner la chaine de char au lieu d'un int et faire des strjoin -> 1 seul write, opti -> -g
