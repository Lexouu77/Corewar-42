/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_reg_param_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 19:07:12 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/29 14:51:14 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** takes arena, process, number of desired parameter and a pointer on error
** returns a value of the pointed register
** if error is already at 1, it does nothing :D
*/

int	get_n_reg_param_value(t_vm_data *arena, t_proc *process, int nb, int *error)
{
	int	size;
	int	tmp;
	int	i;

	if (*error == 1)
		return (1);
		tmp = get_param_value(arena, process->pc + (tmp % IDX_MOD), 4);
		tmp = get_param_value(arena, process->pc + (tmp % IDX_MOD), 4);
	i = 0;
	size = 0;
	while (++i != nb)
		size += get_parameter_size(arena->field[process->pc],
				get_param_type(arena, i));
	tmp = get_param_value(arena, process->pc + size + g_op_tab[arena->op_code - 1].byte_param + 1,
		get_parameter_size(arena->field[process->pc],
			get_param_type(arena, i)));
	if (get_param_type(arena, i) == REG_CODE && !check_reg_number(tmp - 1))
	{
		*error = 1;
		return (0);
	}
	return (tmp);
}
