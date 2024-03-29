/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_waiting_time.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:04:20 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/07 18:06:02 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_process_waiting_time(t_proc *process, t_vm_data *arena)
{
	process->cycles_waiting++;
	if ((arena->verbosity & 16) == 16)
	{
		ft_printf_fd(arena->fd, "Process number : %d", process->number);
		ft_printf_fd(arena->fd, " owned by player number : %d", process->owner);
		ft_printf_fd(arena->fd, " is now waiting for %d cycles!\n",
				process->cycles_waiting);
	}
}

void		increment_waiting_time(t_vm_data *arena, t_proc *process)
{
	if (process->is_waiting)
		display_process_waiting_time(process, arena);
}
