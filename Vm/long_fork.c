/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 11:51:14 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/30 17:25:23 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_lfork_instruction(t_proc *process, t_vm_data *arena)
{
	ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
	ft_printf_fd(arena->fd, " owned by player number : %d",
			process->father->number_of_player);
	ft_printf_fd(arena->fd, " is doing a long fork!");
}

void		long_fork(t_vm_data *arena, t_proc *process)
{
	int	tmp;
	int	i;

	tmp = get_param_value(arena, process->pc + 1, get_n_param_size(arena, 1));
	if (!(process->father->last_process->next =
			(t_proc *)ft_memalloc(sizeof(t_proc))) ||
			!(process->father->last_process->next->reg =
					(int *)ft_memalloc(sizeof(int) * REG_NUMBER)))
			ft_malloc_error();
	process->father->last_process = process->next;
	process->next->number = arena->process_next_number++;
	process->next->owner = process->owner;
	process->next->father = process->father;
	process->next->carry = process->carry;
	i = -1;
	if ((arena->verbosity & 8) == 8)
		display_lfork_instruction(process, arena);
	while (++i < REG_NUMBER)
		process->next->reg[i] = process->reg[i];
	move_pc_without_format(arena, process);
	process->next->pc = (process->pc + tmp) % arena->mem_size;
}
