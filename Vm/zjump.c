/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjump.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 11:18:50 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/08 00:01:22 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_zjump_instruction(t_proc *process, t_vm_data *arena)
{
	ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
	ft_printf_fd(arena->fd, " owned by player number : %d",
			process->father->number_of_player);
	ft_printf_fd(arena->fd, " is doing a zjump!");
	if (!process->carry)
		ft_printf_fd(arena->fd, " And it worked !");
	else
		ft_printf_fd(arena->fd, " And it failed (Reason : carry is !null) !\n");
}

void		zjump(t_vm_data *arena, t_proc *process)
{
	int			tmp;

	if ((arena->verbosity & 8) == 8)
		display_zjump_instruction(process, arena);
	if (process->carry)
		return (move_pc_without_format(arena, process));
	tmp = (short)get_param_value(arena, process->pc + 1,
			get_n_param_size(arena, 1));
	if ((arena->verbosity & 8) == 8)
		ft_printf_fd(arena->fd, " It jumped by %d bytes !\n", tmp);
	ft_printf("TMP = %d | TMP IDX = %d | PC = %d | PC 2 = %d\n", tmp, tmp % IDX_MOD, process->pc, ((process->pc + (tmp % IDX_MOD)) % arena->mem_size));
	process->pc = (process->pc + (tmp % IDX_MOD)) % arena->mem_size;
	if (arena->last_process->pc < 0)
		ft_printf("ZJUMP tmp = %d cycles = %d\n", tmp, arena->cycles);
	if (process->pc < 0)
		process->pc += arena->mem_size;
}
