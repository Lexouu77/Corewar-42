/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 12:19:40 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/14 10:55:32 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_add_instruction(t_proc *process, t_vm_data *arena, int i)
{
	ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
	ft_printf_fd(arena->fd, " owned by player number : %d",
			process->father->number_of_player);
	ft_printf_fd(arena->fd, " is doing an add!");
	if (i)
		ft_printf_fd(arena->fd, " And it worked !");
	else
	{
		ft_printf_fd(arena->fd,
				" And it failed (Reason : invalid register number) !\n");
		process->carry = 0;
	}
}

void		add(t_vm_data *arena, t_proc *process)
{
	int	tmp_one;
	int	tmp_two;
	int	tmp_three;

	tmp_one = arena->field[(process->pc + 2) % arena->mem_size];
	tmp_two = arena->field[(process->pc + 3) % arena->mem_size];
	tmp_three = arena->field[(process->pc + 4) % arena->mem_size];
	if ((tmp_one >= 0 && tmp_one < REG_NUMBER) && (tmp_two >= 0 &&
		tmp_two < REG_NUMBER) && (tmp_three >= 0 && tmp_three < REG_NUMBER))
	{
		if ((arena->verbosity & 8) == 8)
			display_add_instruction(process, arena, 1);
		process->reg[tmp_three] = process->reg[tmp_one] + process->reg[tmp_two];
		process->carry = 1;
		if ((arena->verbosity & 8) == 8)
			ft_printf_fd(arena->fd, "It added r%d(%d) and r%d(rd) in r%d\n",
				tmp_one, process->reg[tmp_one], tmp_two, process->reg[tmp_two],
				tmp_three);
	}
	else if ((arena->verbosity & 8) == 8)
		display_add_instruction(process, arena, 0);
	else
		process->carry = 0;
	process->pc = (process->pc + 5) % arena->mem_size;
}
