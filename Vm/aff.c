/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 12:02:46 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/30 16:54:10 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_aff_instruction(t_proc *process, t_vm_data *arena, int i)
{
	if ((arena->verbosity & 8) == 8)
	{
		ft_printf_fd(arena->fd, "Process number : %d",
				process->number);
		ft_printf_fd(arena->fd, " owned by player number : %d",
				process->father->number_of_player);
		ft_printf_fd(arena->fd, " is doing an aff!");
		if (i)
			ft_printf_fd(arena->fd, " And it worked !");
		else
			ft_printf_fd(arena->fd,
					" And it failed (Reason : invalid register number) !\n");
	}
}

void		aff(t_vm_data *arena, t_proc *process)
{
	int	tmp;
	int	error;

	error = 0;
	tmp = get_n_param_value(arena, process, 1, &error);
	display_aff_instruction(process, arena, error);
	if (!error)
	{
		ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
		ft_printf_fd(arena->fd, " is displaying \"%c\"\n", (tmp % 256));
	}
	move_pc_from_format(arena, process);
}
