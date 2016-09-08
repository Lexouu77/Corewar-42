/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pc_from_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 19:22:20 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/08 20:12:13 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	move_pc_from_format(t_vm_data *arena, t_proc *process)
{
	int			i;
	int			size;
	const int	n_arg = g_op_tab[process->op_code - 1].arg_number;

/*	if (process->op_code != arena->field[process->pc])
	{
		process->pc = (process->pc + 1) % arena->mem_size;
		return ;
	}*/
	i = 0;
	size = 0;
	while (++i <= n_arg)
		size += get_parameter_size(arena->field[process->pc],
				get_param_type(arena, i));
	process->pc = (process->pc + size +
			g_op_tab[arena->op_code - 1].byte_param + 1) % arena->mem_size;
}
