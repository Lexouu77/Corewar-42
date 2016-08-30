/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 17:07:25 by ahamouda          #+#    #+#             */
/*   Updated: 2016/08/30 17:07:43 by ahamouda         ###   ########.fr       */
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

void		sub(t_vm_data *arena, t_proc *process)
{
	int		error;
	int		reg;
	int		reg_two;
	int		reg_three;

	error = 0;
	reg = get_n_reg_param_value(arena, process, 1, &error);
	reg_two = get_n_reg_param_value(arena, process, 2, &error);
	reg_three = get_n_reg_param_value(arena, process, 3, &error);
	move_pc_from_format(arena, process);
	if (error == 1)
		return (display_sub_instruction(process, arena, 0));
	display_sub_instruction(process, arena, 1);
	if ((arena->verbosity & 8) != 8)
		ft_printf_fd(arena->fd, "It stocked r%d (%d) - r%d (%d) in r%d!\n",
		reg - 1, process->reg[reg - 1], reg_two - 1, process->reg[reg_two - 1],
		reg_three - 1);
	process->reg[reg_three - 1] = process->reg[reg - 1] -
		process->reg[reg_two - 1];
}
