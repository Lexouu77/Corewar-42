/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 10:57:07 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/14 12:13:40 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

extern t_op g_op_tab[];

static void	display_st_instruction(t_proc *process, t_vm_data *arena, int i)
{
	ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
	ft_printf_fd(arena->fd, " owned by player number : %d",
			process->father->number_of_player);
	ft_printf_fd(arena->fd, " is doing a st!");
	if (i)
		ft_printf_fd(arena->fd, " And it worked !");
	else
	{
		ft_printf_fd(arena->fd,
				" And it failed (Reason : invalid register number) !\n");
		process->carry = 0;
	}
}

static int	get_arg_val(t_proc *process, t_vm_data *arena, int i, int shift)
{
	if ((arena->field[(process->pc + 1) % arena->mem_size] >> shift
					& 3) == REG_CODE)
		return (process->reg[i - 1]);
	else
		return (i);
}

void		store(t_vm_data *arena, t_proc *process)
{
	int		tmp_one;
	int		tmp_reg;
	int		size;
	int		i;

	tmp_reg = arena->field[(process->pc + 2) % arena->mem_size];
	size = 2;
	tmp_one = get_param_value(arena, process, &size, 4);
	size = 2;
	i = check_reg_number(arena, process, &size);
	if (i)
		tmp_one = get_arg_val(process, arena, tmp_one, 4);
	if ((arena->verbosity & 8) == 8)
		display_st_instruction(process, arena, i);
	if (i && (arena->verbosity & 8) == 8)
		ft_printf_fd(arena->fd, "It did stock r%d at (%d) bytes away\n",
			tmp_reg, tmp_one);
	if (i)
	{
		arena->field[(process->pc + tmp_one) % arena->mem_size] =
			(process->reg[tmp_reg - 1] >> 24) & 0xFF;
		arena->field[(process->pc + tmp_one + 1) % arena->mem_size] =
			(process->reg[tmp_reg - 1] >> 16) & 0xFF;
		arena->field[(process->pc + tmp_one + 2) % arena->mem_size] =
			(process->reg[tmp_reg - 1] >> 8) & 0xFF;
		arena->field[(process->pc + tmp_one + 3) % arena->mem_size] =
			(process->reg[tmp_reg - 1]) & 0xFF;
		//add color/process/fresh field avec une fonction : write_mem(WHERE, WHAT, arena, process)
	}
	process->pc = (process->pc + size) % arena->mem_size;
}
