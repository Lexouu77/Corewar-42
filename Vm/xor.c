/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 14:23:41 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/06 11:44:54 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_xor_instruction(t_proc *process, t_vm_data *arena, int i)
{
	if ((arena->verbosity & 8) != 8)
		return ;
	ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
	ft_printf_fd(arena->fd, " owned by player number : %d",
			process->father->number_of_player);
	ft_printf_fd(arena->fd, " is doing a xor!");
	if (i)
		ft_printf_fd(arena->fd, " And it worked !");
	else
		ft_printf_fd(arena->fd,
				" And it failed (Reason : invalid register number) !\n");
}

void		do_xor(t_vm_data *arena, t_proc *process)
{
	int		error;
	int		var;
	int		var_two;
	int		reg;

	error = 0;
	var = get_n_param_value(arena, process, 1, &error);
	var_two = get_n_param_value(arena, process, 2, &error);
	reg = get_n_reg_param_value(arena, process, 3, &error);
	move_pc_from_format(arena, process);
	if (error == 1)
		return (display_xor_instruction(process, arena, 0));
	display_xor_instruction(process, arena, 1);
	if ((arena->verbosity & 8) == 8)
		ft_printf_fd(arena->fd, "It stocked [%d] ^ [%d] in r%d!\n",
				var, var_two, reg - 1);
	process->reg[reg - 1] = var ^ var_two;
	if (process->reg[reg - 1] == 0)
		process->carry = 0;
	else
		process->carry = 1;
}
