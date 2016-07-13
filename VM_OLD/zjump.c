/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjump.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 11:18:50 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/18 22:45:45 by ahamouda         ###   ########.fr       */
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
	if (process->carry)
		ft_printf_fd(arena->fd, " And it worked !");
	else
		ft_printf_fd(arena->fd, " And it failed (Reason : carry is null) !\n");
}

void		zjump(t_vm_data *arena, t_proc *process)
{
	int			tmp;
	int			size;

	if ((arena->verbosity & 8) == 8)
		display_zjump_instruction(process, arena);
	if (!process->carry)
		return ;
	tmp = get_direct_arg_value(arena, process, &size);
	if ((arena->verbosity & 8) == 8)
		ft_printf_fd(arena->fd, " It jumped by %d bytes !\n", tmp);
	if (process->pc + tmp >= 0)
		process->pc = (process->pc + tmp) % arena->mem_size;
//	else
//		process->pc = arena->mem_size + ((process->pc + tmp) % arena->mem_size); ???? need to test.
}
