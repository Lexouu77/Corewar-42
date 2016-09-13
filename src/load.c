/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 11:07:08 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/12 17:11:38 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_ld_instruction(t_proc *process, t_vm_data *arena, int i)
{
	if ((arena->verbosity & 8) != 8)
		return ;
	ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
	ft_printf_fd(arena->fd, " owned by player number : %d",
			process->father->number_of_player);
	ft_printf_fd(arena->fd, " is doing a ld!");
	if (i)
		ft_printf_fd(arena->fd, " And it worked !");
	else
	{
		ft_printf_fd(arena->fd,
				" And it failed (Reason : invalid register number) !\n");
	}
}

void		load(t_vm_data *arena, t_proc *process)
{
	int		error;
	int		reg;
	int		tmp;

	error = 0;
	reg = 0;
	tmp = get_n_param_value(arena, process, 1, &error);
	reg = get_n_reg_param_value(arena, process, 2, &error);
	move_pc_from_format(arena, process);
	if (error)
		return (display_ld_instruction(process, arena, 0));
	display_ld_instruction(process, arena, 1);
	process->reg[reg - 1] = tmp;
	if ((arena->verbosity & 8) == 8)
		ft_printf_fd(arena->fd, "It stocked %d in reg %d\n", tmp, reg);
	if (tmp == 0)
		process->carry = 0;
	else
		process->carry = 1;
}
