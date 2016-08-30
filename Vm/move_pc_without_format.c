/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pc_without_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 11:36:58 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/30 11:39:59 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	move_pc_without_format(t_vm_data *arena, t_proc *process)
{
	int			i;
	int			size;
	const int	n_arg = g_op_tab[arena->op_code - 1].arg_number;

	i = 0;
	size = 0;
	while (++i <= n_arg)
		size += get_n_param_size(arena, i);
	process->pc = (process->pc + size + 1) % arena->mem_size;
}
