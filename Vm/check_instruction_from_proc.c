/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction_from_proc.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 03:19:28 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/08 22:54:18 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_process_waiting(t_proc *process, t_vm_data *arena)
{
	if (process->is_waiting)
		return ;
	process->op_code = arena->field[process->pc];
	process->format = arena->field[(process->pc + 1) % arena->mem_size];
	process->is_waiting = 1;
	process->cycles_to_wait =
	g_op_tab[arena->field[process->pc] - 1].cycles_to_process;
	if ((arena->verbosity & 16) == 16)
	{
		ft_printf_fd(arena->fd, "Process number : %d", process->number);
		ft_printf_fd(arena->fd, " owned by player number : %d", process->owner);
		ft_printf_fd(arena->fd, " is on a valid op_code (%d)", process->op_code);
		ft_printf_fd(arena->fd, " and will wait for %d cycles!\n",
				process->cycles_to_wait);
		ft_printf_fd(arena->fd, "PC value is now %d !\n", process->pc);
	}
}

static void	display_error_process(t_proc *process, t_vm_data *arena)
{
//	process->pc++;
	if ((arena->verbosity & 16) == 16)
	{
		ft_printf_fd(arena->fd, "Process number : %d", process->number);
		ft_printf_fd(arena->fd, " owned by player number : %d", process->owner);
		ft_printf_fd(arena->fd, " is on an invalid op_code! (%d)", arena->field[process->pc % arena->mem_size]);
		ft_printf_fd(arena->fd, " It PC will increment by one!\n");
		ft_printf_fd(arena->fd, "PC value is now %d !\n", process->pc);
	}
	process->pc = (process->pc + 1) % arena->mem_size;
	process->is_waiting = 0;
}

void		check_instruction_from_proc(t_vm_data *arena, t_proc *process)
{
	process->pc = (process->pc + arena->mem_size) % arena->mem_size;
	if (!process->is_waiting)
	{
		if (process->pc > arena->mem_size || process->pc < 0)
			ft_printf_fd(arena->fd, "ERROR! pc : %d~%d\n", process->pc, process->number);
		if (arena->field[process->pc] > 0 &&
				arena->field[process->pc] <= 16)
			display_process_waiting(process, arena);
		else
			display_error_process(process, arena);
	}
}
