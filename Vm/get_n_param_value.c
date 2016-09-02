/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_param_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 20:07:52 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/01 21:26:11 by ahamouda         ###   ########.fr       */
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
/*
static int	get_idx_mod_value(int tmp, t_vm_data *arena)
{
	if (arena->op_code >= 13 && arena->op_code <= 15)
			return (tmp);
	return (tmp % IDX_MOD);
}
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
	if (get_param_type(arena, i) == REG_CODE && !check_reg_number((char)tmp - 1))
	{
		*error = 1;
		return (1);
	}
//	if (get_param_type(arena, i) == REG_CODE)
//		return ((char)tmp);
	if (get_param_type(arena, i) == IND_CODE)
	{
		//tmp = get_param_value(arena, process->pc + get_idx_mod_value(tmp, arena), DIR_SIZE);
//		ft_printf(" TMP = %d\n", tmp);
	}
	if (get_param_type(arena, i) == REG_CODE)
		return (process->reg[tmp - 1]);
	return (tmp);
}
