/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 14:42:59 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/02 06:28:28 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	display_ldi_instruction(t_proc *process, t_vm_data *arena, int i)
{
	if (!i)
		process->carry = 0;
	if ((arena->verbosity & 8) != 8)
		return ;
	ft_printf_fd(arena->fd, "Process number : %d",
			process->number);
	ft_printf_fd(arena->fd, " owned by player number : %d",
			process->father->number_of_player);
	ft_printf_fd(arena->fd, " is doing a ldi!");
	if (i)
		ft_printf_fd(arena->fd, " And it worked !");
	else
		ft_printf_fd(arena->fd,
				" And it failed (Reason : invalid register number) !\n");
}

void		load_index(t_vm_data *arena, t_proc *process)
{
	int		error;
	int		reg;
	int		tmp;
	int		tmp_two;

	error = 0;
	tmp = get_n_param_value(arena, process, 1, &error);
	tmp_two = get_n_param_value(arena, process, 2, &error);
	reg = get_n_reg_param_value(arena, process, 3, &error);
	tmp += tmp_two;
	tmp = get_param_value(arena, (process->pc + (tmp % IDX_MOD)), REG_SIZE);
	move_pc_from_format(arena, process);
	if (error)
		return (display_ldi_instruction(process, arena, 0));
	display_ldi_instruction(process, arena, 1);
	process->reg[reg - 1] = tmp;
	if (tmp == 0)
		process->carry = 0;
	else
		process->carry = 1;
	if ((arena->verbosity & 8) == 8)
		ft_printf_fd(arena->fd, "It stocked %d in reg %d\n", tmp, reg);
}
