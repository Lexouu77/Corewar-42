/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direct_arg_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 11:31:08 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/18 22:45:48 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

extern t_op g_op_tab[];

int		get_direct_arg_value(t_vm_data *arena, t_proc *process, int *byte_size)
{
	int			tmp;
	const int	pc = process->pc;

	if (!g_op_tab[arena->field[pc]].byte_dir)
	{
		tmp = (arena->field[(pc + 1) % arena->mem_size] << 24 & 0xFF000000);
		tmp |= (arena->field[(pc + 2) % arena->mem_size] << 16 & 0x00FF0000);
		tmp |= (arena->field[(pc + 3) % arena->mem_size] << 8 & 0x0000FF00);
		tmp |= (arena->field[(pc + 4) % arena->mem_size] & 0x000000FF);
		*byte_size = 4;
	}
	else
	{
		tmp = (arena->field[(pc + 1) % arena->mem_size] << 8 & 0x0000FF00);
		tmp |= (arena->field[(pc + 2) % arena->mem_size] & 0x000000FF);
		*byte_size = 2;
	}
	return (tmp);
}
