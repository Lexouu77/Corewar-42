/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_param_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 20:07:52 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/02 08:33:13 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** takes arena, process, number of desired parameter and a pointer on error
** returns a value of the desired parameter
** if error is already at 1, it does nothing :D
** if register, returns the value inside the register
** if register number is invalid, set error to 1
** if indirect type, returns value which is [value] bytes away
*/

long		get_n_param_value(t_vm_data *arena, t_proc *process, int nb,
		int *error)
{
	int		size;
	long	tmp;
	int		i;

	if (*error == 1)
		return (1);
	i = 0;
	size = 0;
	while (++i != nb)
		size += get_parameter_size(arena->field[process->pc],
				get_param_type(arena, i));
	tmp = get_param_value(arena, process->pc + size +
			g_op_tab[arena->op_code - 1].byte_param + 1,
		get_parameter_size(arena->field[process->pc],
			get_param_type(arena, i)));
	if (get_param_type(arena, i) == REG_CODE &&
			!check_reg_number((char)tmp - 1))
	{
		*error = 1;
		return (1);
	}
	if (get_param_type(arena, i) == REG_CODE)
		return (process->reg[tmp - 1]);
	return (tmp);
}
