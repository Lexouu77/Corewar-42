/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_waiting_time.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 01:04:20 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/15 22:25:48 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		increment_waiting_time(t_vm_data *arena)
{
	t_player	*player;
	t_proc		*process;

	if ((arena->verbosity & 2) == 2)
		ft_printf_fd(arena->fd, "We're now in the cycle number : %d\n",
				arena->cycles);
	player = arena->players;
	while (player)
	{
		process = player->process;
		while (process)
		{
			if (process->is_waiting)
				process->cycles_waiting++;
			process = process->next;
		}
		player = player->next;
	}
}
