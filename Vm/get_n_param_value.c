/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_param_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 20:07:52 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/22 21:22:36 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** takes arena, process, number of desired parameter and a pointer on error.
*/

int	get_n_param_value(t_vm_data *arena, t_proc *process, int nb, int *error)
{
	int	size;
	int	tmp;
	int	i;

	if (*error == 1)
		return (1);
	i = 0;
	size = 0;
	while (++i != nb)
		size += get_parameter_size(arena->field[process->pc],
				get_param_type(arena, i));
	tmp = get_param_value(arena, process->pc + size + 2,
		get_parameter_size(arena->field[process->pc],
			get_param_type(arena, i)));
	if (get_param_type(arena, i) == REG_CODE && !check_reg_number(tmp - 1))
	{
		*error = 1;
		return (0);
	}
	if (get_param_type(arena, i) == IND_CODE)
		tmp = get_param_value(arena, process->pc + tmp % IDX_MOD, IND_SIZE); // 2 ou 4 .... faire des tests.
//	process->pc = (process->pc + size) % arena->mem_size; // do it in move pc
	if (get_param_type(arena, i) == REG_CODE)
		return (process->reg[tmp - 1]);
	return (tmp);
}
