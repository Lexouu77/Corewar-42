/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 14:40:48 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/14 11:56:01 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

extern t_op g_op_tab[];

static int	read_one(t_vm_data *arena, t_proc *process, int *size)
{
	int	tmp;

	tmp = arena->field[(process->pc + 1 + *size) % arena->mem_size];
	*size = *size + 1;
	return (tmp);
}

static int	read_two(t_vm_data *arena, t_proc *process, int *size)
{
	int	tmp;

	tmp = (arena->field[(process->pc + 1 + *size) % arena->mem_size] << 8 &
			0x0000FF00);
	tmp |= (arena->field[(process->pc + 2 + *size) % arena->mem_size] &
			0x000000FF);
	*size = *size + 2;
	return (tmp);
}

static int	read_four(t_vm_data *arena, t_proc *process, int *size)
{
	int	tmp;

	tmp = ((arena->field[(process->pc + 1 + *size) % arena->mem_size] << 24) &
			0xFF000000);
	tmp |= (arena->field[(process->pc + 2 + *size) % arena->mem_size] << 16 &
			0x00FF0000);
	tmp |= (arena->field[(process->pc + 3 + *size) % arena->mem_size] << 8 &
			0x0000FF00);
	tmp |= (arena->field[(process->pc + 4 + *size) % arena->mem_size] &
			0x000000FF);
	*size = *size + 4;
	return (tmp);
}

int			get_param_value(t_vm_data *arena, t_proc *process, int *size,
		int shift)
{
	int	i;

	if (shift == 6)
		*size = *size + 1;
	if (((arena->field[(process->pc + 1) % arena->mem_size] >> shift) & 3)
			== REG_CODE)
		i = 1;
	if (((arena->field[(process->pc + 1) % arena->mem_size] >> shift) & 3)
			== IND_CODE)
		i = IND_SIZE;
	if (((arena->field[(process->pc + 1) % arena->mem_size] >> shift) & 3) ==
			DIR_CODE)
	{
		i = g_op_tab[arena->field[process->pc] - 1].byte_dir ? IND_SIZE :
			DIR_SIZE;
	}
	else
		i = (g_op_tab[arena->field[arena->mem_size - 1]].byte_dir) ? IND_SIZE :
			DIR_SIZE;
	if (i == 4)
		return (read_four(arena, process, size));
	else if (i == 2)
		return (read_two(arena, process, size));
	else
		return (read_one(arena, process, size));
}
