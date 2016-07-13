/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 00:47:33 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/13 20:07:49 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	display_field(t_vm_data *arena)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE)
	{
//		if (arena->color)
//			TODO:
		if ((i + 1) % (32 * 2)  == 0 && i != 0)
			ft_printf("%02x\n", arena->field[i]);
		else
			ft_printf("%02x ", arena->field[i]);
	}
}

//Changer printf, retourner la chaine de char au lieu d'un int et faire des strjoin -> 1 seul write, opti -> -g
