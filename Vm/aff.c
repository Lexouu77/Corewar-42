/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 12:02:46 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/20 14:43:41 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_aff_instruction(t_proc *process, t_vm_data *arena, int tmp)
{
	ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
	ft_printf_fd(arena->fd, " owned by player number : %d",
			process->father->number_of_player);
	ft_printf_fd(arena->fd, " is doing an aff!");
	if (check_reg_number(tmp - 1))
		ft_printf_fd(arena->fd, " And it worked !");
	else
		ft_printf_fd(arena->fd,
				" And it failed (Reason : invalid register number) !\n");
}

void		aff(t_vm_data *arena, t_proc *process)
{
	int	tmp;

	tmp = arena->field[(process->pc + 2) % arena->mem_size];
	if ((arena->verbosity & 8) == 8)
		display_aff_instruction(process, arena, tmp);
	if (check_reg_number(tmp - 1))
	{
		ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
		ft_printf_fd(arena->fd, " is displaying \"%c\"\n",
				process->reg[tmp - 1] % 256);
	}
	process->pc = (process->pc + 3) % arena->mem_size;
}
