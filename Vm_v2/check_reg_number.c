/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reg_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 11:01:39 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/14 12:43:52 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

extern t_op g_op_tab[];

int		check_reg_number(t_vm_data *arena, t_proc *process, int *size)
{
	int			i;
	int			x;
	int			ret;
	const int	pc = (process->pc + 1) % arena->mem_size;

	x = -1;
	ret = 1;
	while (++x < 4)
	{
		i = 0;
		if (((arena->field[pc] >> (6 - 2 * x)) & 3) == REG_CODE)
			i = 1;
		if (((arena->field[pc] >> (6 - 2 * x)) & 3) == IND_CODE)
			i = IND_SIZE;
		if (((arena->field[pc] >> (6 - 2 * x)) & 3) == DIR_CODE)
			i = (g_op_tab[arena->field[process->pc] - 1].byte_dir) ? IND_SIZE :
			DIR_SIZE;
		if (i == 1 && (arena->field[(process->pc + 1 + *size) % arena->mem_size]
				< 0 || (arena->field[(process->pc + 1 + *size) %
					arena->mem_size] >= REG_NUMBER)))
			ret = 0;
		*size = *size + i;
	}
	return (ret);
}
