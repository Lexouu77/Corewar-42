/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 12:19:40 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/22 19:49:37 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_sub_instruction(t_proc *process, t_vm_data *arena, int i)
{
	process->carry = i;
	if ((arena->verbosity & 8) != 8)
		return ;
	ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
	ft_printf_fd(arena->fd, " owned by player number : %d",
			process->father->number_of_player);
	ft_printf_fd(arena->fd, " is doing a sub!");
	if (i)
		ft_printf_fd(arena->fd, " And it worked !");
	else
		ft_printf_fd(arena->fd,
				" And it failed (Reason : invalid register number) !\n");
}

void		add(t_vm_data *arena, t_proc *process)
{
	const int	reg = get_param_value(arena, process->pc + 2, 1);
	const int	reg_two = get_param_value(arena, process->pc + 3, 1);
	const int	reg_three = get_param_value(arena, process->pc + 4, 1);

	if ((check_reg_number(reg - 1) & check_reg_number(reg_two - 1) &
			check_reg_number(reg_three - 1)) == 0)
	{
		process->pc = (process->pc + 5) % arena->mem_size;
		return (display_sub_instruction(process, arena, 0));
	}
	display_sub_instruction(process, arena, 1);
	if ((arena->verbosity & 8) != 8)
		ft_printf_fd(arena->fd, "It stocked r%d (%d) - r%d (%d) in r%d!\n",
				reg - 1, process->reg[reg - 1], reg_two,
				process->reg[reg_two - 1], reg_three - 1);
	process->reg[reg_three - 1] = process->reg[reg - 1] -
		process->reg[reg_two - 1];
	process->pc = (process->pc + 5) % arena->mem_size;
}
