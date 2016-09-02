/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction_from_proc.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 03:19:28 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/02 03:45:11 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_process_waiting(t_proc *process, t_vm_data *arena)
{
	if (process->is_waiting)
		return ;
	process->is_waiting = 1;
	process->cycles_to_wait =
	g_op_tab[arena->field[process->pc] - 1].cycles_to_process;
	if ((arena->verbosity & 16) == 16)
	{
		ft_printf_fd(arena->fd, "Process number : %d", process->number);
		ft_printf_fd(arena->fd, " owned by player number : %d", process->owner);
		ft_printf_fd(arena->fd, " is on a valid op_code");
		ft_printf_fd(arena->fd, " and will wait for %d cycles!\n",
				process->cycles_to_wait);
		ft_printf_fd(arena->fd, "PC value is now %d !\n", process->pc);
	}
}

static void	display_error_process(t_proc *process, t_vm_data *arena)
{
	process->pc = (process->pc + 1) % arena->mem_size;
	process->is_waiting = 0;
	if ((arena->verbosity & 16) == 16)
	{
		ft_printf_fd(arena->fd, "Process number : %d", process->number);
		ft_printf_fd(arena->fd, " owned by player number : %d", process->owner);
		ft_printf_fd(arena->fd, " is on an invalid op_code!");
		ft_printf_fd(arena->fd, " It PC will increment by one!\n");
		ft_printf_fd(arena->fd, "PC value is now %d !\n", process->pc);
	}
}

void		check_instruction_from_proc(t_vm_data *arena)
{
	t_player	*player;
	t_proc		*process;

	player = arena->players;
	while (player)
	{
		process = player->process;
		while (process)
		{
//			if (!process->is_waiting)
//			{
				if (arena->field[process->pc] > 0 &&
						arena->field[process->pc] <= 16)
					display_process_waiting(process, arena);
				else
					display_error_process(process, arena);
//			}
			process = process->next;
		}
		player = player->next;
	}
}
