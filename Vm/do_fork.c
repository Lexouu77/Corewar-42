/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 11:51:14 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/07 23:35:15 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_fork_instruction(t_proc *process, t_vm_data *arena)
{
	if ((arena->verbosity & 8) == 8)
	{
		ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
		ft_printf_fd(arena->fd, " owned by player number : %d",
			process->father->number_of_player);
		ft_printf_fd(arena->fd, " is doing a fork!");
	}
}

void		do_fork(t_vm_data *arena, t_proc *process)
{
	int	tmp;
	int	i;
/*
	tmp = (short)get_param_value(arena, process->pc + 1,
			get_n_param_size(arena, 1));
	if (!(process->father->last_process->next =
			(t_proc *)ft_memalloc(sizeof(t_proc))) ||
			!(process->father->last_process->next->reg =
			(int *)ft_memalloc(sizeof(int) * REG_NUMBER)))
		ft_malloc_error();
	process->father->number_of_process++;
	process->father->last_process->next->prev = process->father->last_process;
	process->father->last_process = process->father->last_process->next;
	process->father->last_process->number = arena->process_next_number++;
	process->father->last_process->owner = process->owner;
	process->father->last_process->lives = process->lives;
	process->father->last_process->father = process->father;
	process->father->last_process->carry = process->carry;
	i = -1;
	display_fork_instruction(process, arena);
	while (++i < REG_NUMBER)
		process->father->last_process->reg[i] = process->reg[i];
	process->father->last_process->pc = (process->pc + (tmp % IDX_MOD)) %
		arena->mem_size;
	move_pc_without_format(arena, process);
}*/
	tmp = (short)get_param_value(arena, process->pc + 1,
			get_n_param_size(arena, 1));
	if (!(arena->last_process->next =
			(t_proc *)ft_memalloc(sizeof(t_proc))) ||
			!(arena->last_process->next->reg =
					(int *)ft_memalloc(sizeof(int) * REG_NUMBER)))
		ft_malloc_error();
	arena->number_of_process++;
	arena->last_process->next->prev = arena->last_process;
	arena->last_process = arena->last_process->next;
	arena->last_process->number = arena->process_next_number++;
	arena->last_process->owner = process->owner;
	arena->last_process->lives = process->lives;
	arena->last_process->father = process->father;
	arena->last_process->carry = process->carry;
	i = -1;
	if ((arena->verbosity & 8) == 8)
		display_fork_instruction(process, arena);
	while (++i < REG_NUMBER)
		arena->last_process->reg[i] = process->reg[i];
	arena->last_process->pc = (process->pc + (tmp % IDX_MOD)) % arena->mem_size;
	move_pc_without_format(arena, process);
//	ft_printf("tmp = (%d)=%d\n", tmp, tmp % IDX_MOD);
	if ((arena->verbosity & 8) == 8)
	{
		ft_printf_fd(arena->fd, "Process pc : %d, new one %d \n", process->pc, arena->last_process->pc);
	}
}
