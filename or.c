/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 16:12:26 by ahamouda          #+#    #+#             */
/*   Updated: 2016/06/14 09:46:39 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_or_instruction(t_proc *process, t_vm_data *arena, int i)
{
	ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
	ft_printf_fd(arena->fd, " owned by player number : %d",
			process->father->number_of_player);
	ft_printf_fd(arena->fd, " is doing an or!");
	if (i)
		ft_printf_fd(arena->fd, " And it worked !");
	else
	{
		ft_printf_fd(arena->fd,
				" And it failed (Reason : invalid register number) !\n");
		process->carry = 0;
	}
}

void		do_or(t_vm_data *arena, t_proc *process)
{
	int	tmp_one;
	int	tmp_two;
	int	tmp_reg;
	int	size;

	size = 1;
	process->pc = (process->pc + 1) % arena->mem_size;
	tmp_one = get_param_value(arena, process, &size, 6);
	tmp_two = get_param_value(arena, process, &size, 4);
	tmp_reg = arena->field[(process->pc + size++) % arena->mem_size];
	if (tmp_reg >= 0 && tmp_reg < REG_NUMBER)
	{
		if ((arena->verbosity & 8) == 8)
			display_or_instruction(process, arena, 1);
		process->reg[tmp_reg] = tmp_one | tmp_two;
		process->carry = 1;
		if ((arena->verbosity & 8) == 8)
			ft_printf_fd(arena->fd, "It did [%d | %d] and stocked it in r%d\n",
				tmp_one, tmp_two, tmp_reg);
	}
	else if ((arena->verbosity & 8) == 8)
		display_or_instruction(process, arena, 0);
	else
		process->carry = 0;
	process->pc = (process->pc + size + 1) % arena->mem_size;
}
